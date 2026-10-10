// #include <iostream>

// //使用链表
// struct node {
//     int number;
//     node* next;
//     node* prev;
// };//构建双向链表

// void insertList(node* head, node* inserter, int pos, int dir) {
//     node* cur =  head;
//     //寻找插入同学的位置
//     while (cur->number != pos) {
//         cur = cur->next;
//     }
//     //插入的方向左右
//     if (dir == 0) {
//         cur->prev->next = inserter->prev;
//         inserter->prev = cur->prev->next;
//         inserter->next = cur->prev;
//         cur->prev = inserter->next;
//     } else if (dir == 1) {
//         cur->next->prev = inserter->next;
//         inserter->next = cur->next->prev;
//         cur->next = inserter->prev;
//         inserter->prev = cur->next;
//     }
// }

// void remove(node* head, node* tail, int target) {
//     node* cur = head;
//     while (cur != tail) {
//         if (cur->number == target) {

//             break;
//         } 
//         else {
//             cur = cur->next;
//         }
//     }
// }

// void print(node* head, node* tail) {
//     node* cur = head;
//     while (cur != tail) {
//         std::cout << cur->number << std::endl;
//     }
// }

// int main() {
//     int N, M;
//     std::cin >> N;
    
//     //第一个学生初始化
//     node* first = new node;
//     node* head = first; //维护一个头指针
//     node* tail = first; //维护一个尾指针
    
//     first->number = 1;
//     first->next = nullptr;
//     first->prev = nullptr;//第一个同学初始化
    
//     for (int i = 2; i <= N; i++) {
//         //将对应的学生插入左边或者右边
//         int pos, dir;
//         std::cin >> pos >> dir;
//         node* inserter = new node;
//         inserter->number = i;
//         inserter->next = nullptr;
//         inserter->prev = nullptr;

//         insertList(head, inserter, pos, dir);
//     }
    
//     std::cin >> M;
//     for (int i = 1; i <= M; i++) {
//         //将x号同学从队列中移去，否则忽略
//         int target;
//         std::cin >> target;
//         remove(head, tail, target);
//     }
    
//     print(head, tail);
// }

//AC1
// #include <iostream>

// const int MAXN = 100005;

// //双向节点链表
// struct node {
//     int number;
//     node* prev;
//     node* next;
//     node(int val = 0) : number(val), prev(nullptr), next(nullptr) {}
// };

// node* nodes[MAXN]; // 记录编号到节点指针的映射，实现定位

// //插入操作 : 直接将inserter插入左边或者右边
// void insertList(node* cur, node* inserter, int dir) {
//     if (dir == 0) { //插入到cur的左边
//         inserter->prev = cur->prev;
//         inserter->next = cur;
//         cur->prev->next = inserter;
//         cur->prev = inserter;
//     } else {
//         inserter->prev = cur;
//         inserter->next = cur->next;
//         cur->next->prev = inserter;
//         cur->next = inserter;
//     }
// }

// //删除操作：断开指针
// void removeNode(int target) {
//     node* cur = nodes[target];
//     if (cur == nullptr) return; //已经被删除或者不存在，直接忽略

//     cur->prev->next = cur->next;
//     cur->next->prev = cur->prev;

//     delete cur;
//     nodes[target] = nullptr; //标记为已经移除
// }

// int main() {
//     //提升I/O效率
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int N;
//     if (!(std::cin >> N)) return 0;

//     //建立哨兵头尾节点，避免被各种边界nullptr特判
//     node* head = new node(0);
//     node* tail = new node(0);
//     head->next = tail;
//     tail->prev = head;

//     //初始化第一个学生
//     node* first = new node(1);
//     nodes[1] = first;
//     insertList(head, first, 1); //插入head的右侧

//     //依次插入2~N名学生
//     for (int i = 2; i <= N; i++) {
//         int pos, dir;
//         std::cin >> pos >> dir;
//         node* inserter = new node(i);
//         nodes[i] = inserter;
//         insertList(nodes[pos], inserter, dir);
//     }

//     //移除M个学生
//     int M;
//     std::cin >> M;
//     for (int i = 0; i < M; i++) {
//         int target;
//         std::cin >> target;
//         removeNode(target);
//     }

//     //输出链表内容
//     bool first_out = true;
//     for (node* cur = head->next; cur != tail; cur = cur->next) {
//         if (!first_out) std::cout << ' ';
//         std::cout << cur->number;
//         first_out = false;
//     }
//     std::cout << '\n';
//     return 0;
// }

//AC2
//使用数组模拟双向链表
#include <iostream>

const int MAXN = 100005;

//l[i]表示i左边同学的编号，r[i]表示i右边同学的编号
int l[MAXN], r[MAXN];
bool deleted[MAXN];

//在节点k的右侧插入节点i
void insert_right(int k, int i) {
    r[i] = r[k];
    l[i] = k; 
    l[r[k]] = i;
    r[k] = i;
}

//在节点k的左侧插入节点i
void insert_left(int k, int i) {
    insert_left(l[k], i);
}

//移除节点x
void remove_node(int x) {
    if (deleted[x]) return;
    deleted[x] = true;

    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

int main() {
    //优化标准输入输出流
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;

    //初始化：0为虚拟头结点，1为初始入队的同学
    r[0] = 1;
    l[1] = 0;
    r[1] = 0;

    for (int i = 2; i <= n; ++i) {
        int k, p;
        std::cin >> k >> p;
        if (p == 0) {
            insert_left(k, i);
        } else {
            insert_right(k, i);
        }
    }

    int m;
    std::cin >> m;
    for (int j = 0; j < m; ++j) {
        int x;
        std::cin >> x;
        remove_node(x);
    }

    //从头结点右边开始顺序输出
    bool first = true;
    for (int cur = r[0]; cur != 0; cur = r[cur]) {
        if (!first) std::cout << ' ';
        std::cout << cur;
        first = false;
    }
    std::cout << '\n';
    return 0;
}

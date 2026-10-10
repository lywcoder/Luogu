// #include <iostream>
// #include <queue>

// int main() {
//     int n, m;
//     std::cin >> n >> m;

//     std::queue<int> q;
//     for (int i = 1; i <= n; i++) {
//         q.push(i); //编号为1-n的人入队
//     }
//     int cnt = 0; //当前报数
//     while (!q.empty()) {
//         int cur = q.front(); //取出队首
//         q.pop();
//         cnt++; //报数加1
//         if (cnt == m) {
//             std::cout << cur << " "; //报到m，出圈
//             cnt = 0; //重新从1开始报数
//         } else {
//             q.push(cur); //未报到m回到队尾
//         }
//     }
//     return 0;
// }

// #include <iostream>

//使用数组模拟链表
// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int prev[105], next[105];
//     for (int i = 1; i <= n; i++) {
//         prev[i] = i - 1;
//         next[i] = i + 1;
//     }

//     prev[1] = n;
//     next[n] = 1;

//     int cur = 1;
//     int cnt = 0;
//     while (cnt < n) {
//         //移动m-1步数，因为当前的节点是第一个
//         for (int i = 1; i < m; i++) {
//             cur = next[cur];
//         }
//         //此时的cur是要出圈的人
//         std::cout << cur << " ";
//         cnt++;
//         //删除cur
//         int p = prev[cur];
//         int nxt = next[cur];
//         cur = nxt;
//         return 0;
//         return 0;
//     }
//     return 0;
// }
// 

// #include <iostream>
// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     bool out[105] = {false};
//     int cnt = 0; //当前报数
//     int total = 0; //已经出圈的人数
//     int i = 0;//当前位置
//     while (total < n) {
//         i = i % n + 1;
//         if (out[i]) continue;
//         cnt++;
//         if (cnt == m) {
//             std::cout << i << " ";
//             out[i] = true;
//             total++;
//             cnt = 0;
//         }
//     }
//     return 0;
// }

//joseph problem
//使用数学递推公式进行计算
int josephus(int n, int m) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + m) % i;
    }
    return res + 1;
}

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    int idx = 0;
    while (!people.empty()) {
        idx = (idx + m - 1) % people.size();
        std::cout << people[idx] << " ";
        people.erase(people.begin() + idx);
    }
    return 0;
}
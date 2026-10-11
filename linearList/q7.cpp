// #include <iostream>

// void nation(int idx, int** time, int n) {
//     int nation = 0; //开始不同的数是0个
//     int cnt = idx;
//     while (time[idx][0] - time[cnt][0] < 86400) {
//         for (int i = 1; i <= time[cnt][0]; i++) {
//             for (int j = 1; j <= time[cnt][i]; j++) {
//                 if (time[cnt][i] == time[cnt][j]) break;
//             }
//             nation++; //进行不同人数的查找
//         }
//         cnt--; //查找上一艘船是否符合条件
//     }
//     std::cout << nation << '\n';
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n;
//     std::cin >> n; //输入一共n艘船

//     int** time = new int*[n]; //建立一个n的指针数组
//     for (int i = 0; i < n; i++) { 
//         int t, k; //输入船上的游客数量
//         std::cin >> t >> k; 
//         time[i] = new int[k + 1]; // 开辟一个k+1的空间，第一个位置放的是每个时间这个船上人的数量
//         time[i][0] = t;
//         for (int j = 1; j <= k; j++) {
//             std::cin >> time[i][j]; //记录每个人的国籍
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         nation(i, time, n); //需要找到前面一天时间范围内一共有多少个不同的数
//     }

//     for (int i = 0; i < n; i++) {
//         delete[] time[i];
//     }
//     delete[] time;

//     return 0;
// }
// 

// #include <iostream>
// #include <vector>

// struct Boat {
//     int t;
//     int k;
//     std::vector<int> passengers;
// };

// // 从当前船idx往前查符合时间条件的船只
// void nation(int idx, const std::vector<Boat> boats) {
//     //标记出现过的国籍；
//     // static避免每次调用重复在栈上开辟大数组
//     static bool vis[100005];
//     std::fill(std::begin(vis), std::end(vis), false);

//     int unique_nations = 0;
//     int cnt = idx;

//     while (cnt >= 0 && boats[idx].t - boats[cnt].t < 86400) {
//         for (int i = 0; i < boats[cnt].k; i++) {
//             int country = boats[cnt].passengers[i];
//             //如果这个国籍之前没有被记录过
//             if (!vis[country]) {
//                 vis[country] = true;
//                 unique_nations++;
//             }
//         }
//         cnt--;
//     }
    
//     std::cout << unique_nations << '\n';
// }

// int main() {
//     //优化I/O速度
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n;
//     if (!(std::cin >> n)) return 0;

//     std::vector<Boat> boats(n);

//     //输入n艘船的数据
//     for (int i = 0; i < n; i++) {
//         std::cin >> boats[i].t >> boats[i].k;
//         boats[i].passengers.resize(boats[i].k);
//         for (int j = 0; j < boats[i].k; j++) {
//             std::cin >> boats[i].passengers[j];
//         }
//     }

//     //依次计算每艘船到达时的结果
//     for (int i = 0; i < n; ++i) {
//         nation(i, boats);
//     }

//     return 0;
// }
#include <iostream>
#include <queue>

struct Passenger {
    int time;
    int nation;
};

const int MAX_NATION = 100005;
int cnt[MAX_NATION]; //cnt[x]表示当前窗口中国籍为x的人数
int ans = 0; //当前有效窗口内不同国家的数量

int main() {
    //优化I/O速度
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;

    std::queue<Passenger> q;

    for (int i = 0; i < n; ++i) {
        int t, k;
        std::cin >> t >> k;

        //将本艘船的所有乘客加入窗口
        for (int j = 0; j < k; ++j) {
            int nation;
            std::cin >> nation;
            if (cnt[nation] == 0) {
                ans++; //出现新国家
            }
            cnt[nation]++;
            q.push({t, nation});
        }
        
        //2.弹出超过24h的乘客
        while (!q.empty() && q.front().time <= t - 86400) {
            int old_nation = q.front().nation;
            cnt[old_nation]--;
            if (cnt[old_nation] == 0) {
                ans--;
            }
            q.pop();
        }
    }

    //3. 输出当前时刻的答案
    std::cout << ans << '\n';

    return 0;
}


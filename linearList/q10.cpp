// #include <iostream>
// #include <vector>

// int main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> turnover(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> turnover[i];
//     }
    
//     int sum = turnover[0];
//     for (int i = 1; i < n; ++i) {
//         int min = 10000001;
//         std::vector<int> change(i);
//         for (int j = 0; j < i; ++j) {
//             change[j] = std::abs(turnover[i] - turnover[j]);
//             if (change[j] < min) {
//                 min = change[j];
//             }
//         }
        
//         sum += min;
//     }

//     std::cout << sum;
    
//     return 0;
// }
// 

#include <climits>
#include <iostream>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;

    std::set<int> s;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        if (i == 0) {
            sum += x; //第一天直接加上营业额
        } else {
            //lower_bound返回指向第一个>= x的元素的迭代器
            auto it = s.lower_bound(x);
            int min_diff = INT_MAX;

            //情况1：存在 >= x的最小元素,后继
            if (it != s.end()) {
                min_diff = std::min(min_diff, std::abs(*it - x));
            }
            //情况2，存在<= x的最大元素,前驱，就是it往后退一格
            if (it != s.begin()) {
                min_diff = std::min(min_diff, std::abs(*std::prev(it) - x));
            }

            sum += min_diff;
        }
        s.insert(x);
    }

    std::cout << sum << '\n';
    return 0;
}
// #include <iostream>
// #include <stack>
// #include <vector>

// int main() {
//     int q;
//     std::cin >> q; //q个询问，代表询问次数

//     while (q > 0) {
//         int n;
//         std::cin >> n;
//         std::stack<int> pushed;
//         for (int i = 0; i < n; i++) {
//             int t;
//             std::cin >> t;
//             pushed.push(t);
//         }

//         std::vector<int> poped(n);
//         for (int i = 0; i < n; i++) {
//             std::cin >> poped[i];
//         }

//         std::vector<int> output(n);
//         for (int i = 0; i < n; i++) {
//             int t = pushed.top();
//             pushed.pop();
//             output[i] = t;
//         }

//         if (output == poped) {
//             std::cout << "Yes" << std::endl;
//         } else {
//             std::cout << "No" << std::endl;
//         }
//         q--;
//     }
// }
// 
#include <iostream>
#include <vector>
#include <stack>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> pushed(n);
    std::vector<int> popped(n);
    
    for (int i = 0; i < n; i++) std::cin >> pushed[i];
    for (int i = 0; i < n; i++) std::cin >> popped[i];

    std::stack<int> st;
    int pop_idx = 0; //标记当前等待匹配的Popped元素下标

    //模拟入栈过程
    for (int i = 0; i < n; i++) {
        st.push(pushed[i]);
        //只要栈不为空并且栈顶元素匹配当前出栈的元素，就会不断弹出
        while (!st.empty() && st.top() == popped[pop_idx]) {
            st.pop();
            pop_idx++;
        }
    }

    //如果最终栈被清空，说明序列合法
    if (st.empty()) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q; 
    if (std::cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}
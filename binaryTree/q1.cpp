// #include <iostream>
// #include <vector>

// int main() {
//     int n;
//     std::cin >> n;
//     int country = 1 << n;
//     //一共2^n个国家参赛
//     std::vector<int> value(country);

//     for (int i = 0; i < country; ++i) {
//         std::cin >> value[i];
//     }

//     int leftMax = 0;
//     for (int i = 0; i < country / 2; ++i) {
//         if (value[leftMax] < value[i]) {
//             leftMax = i;
//         }
//     }

//     int rightMax = country / 2;
//     for (int i = country / 2; i < country; ++i) {
//         if (value[rightMax] < value[i]) {
//             rightMax = i;
//         }
//     }

//     int silver = ((value[leftMax] < value[rightMax]) ? leftMax : rightMax) + 1;
//     std::cout << silver;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     int n;
//     std::cin >> n;
    
//     int total = 1 << n;       // 2^n 个国家 (使用位运算左移)
//     int half = 1 << (n - 1);  // 2^(n-1)，即左右半区的分界线

//     std::vector<int> value(total);
//     for (int i = 0; i < total; ++i) {
//         std::cin >> value[i];
//     }

//     // 1. 找左半区 [0, half - 1] 能力值最大的下标
//     int leftMax = 0; // 从左半区第一个元素（下标 0）开始
//     for (int i = 0; i < half; ++i) {
//         if (value[leftMax] < value[i]) {
//             leftMax = i; // 全程保持 0-indexed 下标，不加 1
//         }
//     }

//     // 2. 找右半区 [half, total - 1] 能力值最大的下标
//     int rightMax = half; // 从右半区第一个元素（下标 half）开始
//     for (int i = half; i < total; ++i) {
//         if (value[rightMax] < value[i]) {
//             rightMax = i;
//         }
//     }

//     // 3. 比较两个半区冠军的【能力值】，能力值较小的那个是亚军
//     int silver_idx = (value[leftMax] < value[rightMax]) ? leftMax : rightMax;

//     // 4. 只在最后输出时 +1，将数组下标转换为 1-indexed 的国家编号
//     std::cout << silver_idx + 1 << "\n";

//     return 0;
// }
// 
// algorithm库里自带一个专门找区间最大元素位置函数std::max_element
// 
// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main() {
//     int n;
//     std::cin >> n;
//     int total = 1 << n;
//     int half = 1 << (n - 1);

//     std::vector<int> v(total);
//     for (int i = 0; i < total; ++i) std::cin >> v[i];

//     //max_element 返回指向最大值的迭代器，减去对应的v.begin()就得到了他的数组
//     int leftMax = std::max_element(v.begin(), v.begin() + half) - v.begin();
//     int rightMax = std::max_element(v.begin() + half, v.end()) - v.begin();

//     int silver = (v[leftMax] < v[rightMax]) ? leftMax : rightMax;
//     std::cout << silver + 1 << '\n';
//     return 0;
// }
// 一、 满二叉树的数组编号规律当有 $2^n$ 个国家参赛时，整场淘汰赛刚好构成一棵有 $n + 1$ 层的满二叉树，
// 总共有 $2^{n+1} - 1$ 个节点：叶子节点（最初参赛的 $2^n$ 个国家）：
// 恰好位于数组下标 [2^n, 2^(n+1) - 1] 的位置。(例如样例 $n = 3$，$2^3 = 8$ 个国家，
// 它们直接住在数组下标 8 ~ 15 号房间里。)非叶子节点（每一轮晋级后的胜者）：
// 位于数组下标 [1, 2^n - 1] 的位置。决赛与半决赛的位置（固定不变！）：tree[1]（根节点）
// ：全场的总冠军。tree[2]（根的左孩子）：左半区冠军（决赛选手之一）。tree[3]（根的右孩子）
// ：右半区冠军（决赛选手之二）。因此，建好这棵树后，我们根本不用遍历，直接比较 tree[2] 和 tree[3] 谁的能力值小，谁就是亚军！
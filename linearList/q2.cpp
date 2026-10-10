#include <iostream>
#include <vector>
#include <map>

int main() {
    //加速I/O读写
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    //每个柜子使用一个map进行维护,key是格子编号j,value作为物品k
    std::vector<std::map<int, int>> cabin(n + 1);

    while (q--) {
        int op, i, j;
        std::cin >> op >> i >> j;

        if (op == 1) {
            int k;
            std::cin >> k;
            if (k == 0) {
                cabin[i].erase(j);
            } else {
                cabin[i][j] = k;
            }
        } else if (op == 2) {
            //直接读取对应格子和柜子的存物
            std::cout << cabin[i][j] << "\n";
        }
    }
    return 0;
}

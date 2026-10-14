// #include <iostream>
// #include <vector>

// int main() {
//     int m, n;
//     std::cin >> m >> n;
//     std::vector<int> article(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> article[i];
//     }

//     std::vector<int> cache(m, -1);
//     int cnt = 0;
//     // 最后要求找到软件去外存查字典的数目，其实就是每次入队的数目，
//     // 如果需要查找的单词在内存，直接cache命中，如果cache未命中，则需要向外存查找并且入队
//     for (int i = 0; i < n; ++i) {
//         bool hit = false;
//         for (int j = 0; j < cache.size(); j++) {
//             if (cache[j] == article[i]) {
//                 hit = true;
//                 break;
//             }
//         }
//         if (hit == false) {
//             for (int k = 0; k < cache.size() - 1; ++k) {
//                 cache[k] = cache[k + 1];
//             }
//             cache[cache.size() - 1] =  article[i];
//             cnt++;
//         }
//     }

//     std::cout << cnt << std::endl;

//     return 0;
// }

//自己成功AC的代码

#include <iostream>
#include <queue>

bool in_memory[1005]; // 记录单词当前是否在内存中
std::queue<int> mem; //维护内存中单词的先后顺序

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    int ans = 0; //记录查词典的次数

    for (int i = 0; i < n; ++i) {
        int word;
        std::cin >> word;

        //如果内存中没有这个单词，需要去外存查词典
        if (!in_memory[word]) {
            ans++; //查词典次数++

            // 如果内存已满，淘汰最早进入内存的单词
            if (mem.size() == m) {
                int oldest = mem.front();
                mem.pop();
                in_memory[oldest] = false; //标记该单词已经移除内存
            }

            // 将新单词存入内存
            mem.push(word);
            in_memory[word] = true;
        }
        //如果已经在内存中，什么都不用做 （FIFO不会因为命中缓存而改变单词在队列中的位置
    }
    std::cout << ans << '\n';

    return 0;
}

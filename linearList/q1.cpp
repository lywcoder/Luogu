// #include <iostream>

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int* arr = new int[n];
//     for (int i = 0; i < n; i++) {
//         std::cin >> arr[i];
//     }

//     int* ask = new int[m];
//     for (int i = 0; i < m; i++) {
//         std::cin >> ask[i];
//     }
    
//     for (int i = 0; i < m; i++) {
//         std::cout << arr[ask[i] - 1] << std::endl;
//     }

//     delete[] arr;
//     delete[] ask;

//     return 0;
// }
// 
// #include <cstdio>
// int a[2000001];
// int main() {
//     int n, m, sum;
//     scanf("%d %d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 1; i <= m; i++) {
//         scanf("%d", &sum);
//         printf("%d\n", a[sum]);
//     }
// }

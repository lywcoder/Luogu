#include <iostream>
#include <stack>

int main() {
    std::string s;
    std::cin >> s;

    std::stack<long long> st;
    long long num = 0;

    for (auto c : s) {
        if (c == '@') break; //结束符，退出

        if (isdigit(c)) {
            num = num * 10 + (c - '0'); //如果遇到多位数的时候，十位数字每多一位，前面的数字就要左移一位，并且加上新的一位
            //这里就是将当前字符转换为数字，并且拼接到已经有的数字的末尾,积累操作数
        } else if (c == '.') {
            st.push(num); //将完整的数字进行压栈
            num = 0; //清空，准备读下一个数字
        } else { //运算符
            long long b = st.top(); //右操作数
            st.pop(); 
            long long a= st.top(); //左操作数
            st.pop();

            long long res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;

            st.push(res); //将结果压入栈
        }
    }
    std::cout << st.top() << '\n';// 栈顶就是答案
    return 0;
}
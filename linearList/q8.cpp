// 通过栈模拟配合标记数组
// 维护一个栈st，用来存储尚未配对的左括号的下标
// 用一个bool数组matched来标记字符串中每个位置的字符是否成功配对
// 从左到右遍历字符串s：
// 如果当前字符是左括号，将其下标入栈
// 如果当前字符是右括号，就先查看栈顶元素（就是左侧离他最近的未匹配左括号）
// 如果栈顶左括号和当前的右括号类型匹配，就是配对成功，标记Matched为true，并且将栈顶元素出栈
// 如果栈顶左括号和当前右括号类型不匹配，或者栈为空，就是配对失败，右括号保持不匹配，左括号留在栈中
#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool is_match(char left, char right) {
    return (left == '(' && right == ')') ||(left == '[' && right == ']');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) return 0;
    
    int n = s.length();
    std::vector<bool> matched(n, false);
    std::stack<int> st; //存储未匹配的左括号下标 

    //扫描字符串进行配对
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(i);
        } else if (s[i] == ')' || s[i] == ']') {
            if (!st.empty()) {
                int top_idx = st.top();
                if (is_match(s[top_idx], s[i])) {
                    matched[top_idx] = true;
                    matched[i] = true;
                    st.pop();
                }
                //如果类型不匹配，配对失败，栈顶左括号留存，当前有括号保持未匹配
            }
        }
    }

    //2. 根据配对标记构造最终答案
    std::string ans = "";
    for (int i = 0; i < n; ++i) {
        if (matched[i]) {
            ans += s[i];
        } else {
            if (s[i] == '(' || s[i] == ')') {
                ans += "()";
            } else if (s[i] == '[' || s[i] == ']') {
                ans += "[]";
            }
        }
    }

    std::cout << ans << "\n";
    
    return 0;
}

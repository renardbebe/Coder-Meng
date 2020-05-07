#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

string str, s;

int dfs(int idx) { //循环内套递归，实质上仅遍历一次
    char ch;
    int cnt;
    for (ch = str[idx++]; ch != ')' && idx < str.size(); ch = str[idx++]){
        //因只单次处理括号的内容，所以设置右括号为跳出条件
        for (cnt = 0; isdigit(ch); ch = str[idx++]) 
            cnt = cnt * 10 + ch - '0'; // 是数字的情况
        if (!cnt) cnt = 1;
        //数字后不是左括号就是字母
        if (ch == '('){  // 是左括号的情况，就递归输出cnt次的括号里的内容（哪怕前面无数字，cnt也为1）
            int tmp;
            while (cnt--)
                tmp = dfs(idx);
            idx = tmp;   // 匹配的右括号后面一个位置
        }
        else while (cnt--) s += ch; //是字母的情况，就输出cnt次的字母（哪怕前面无数字，cnt也为1）
    }
    if (ch == ')') return idx;
    else if (isalpha(ch)) s += ch;
}

int main () {
    int T;
    cin >> T;

    for (int kase = 1; kase <= T; kase++) {
        cin >> str;
        s = "";

        dfs(0);
        // cout << s << endl;

        int w = 1, h = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'S') {
                h += 1;
            }
            else if (s[i] == 'N') {
                h -= 1;
            }
            else if (s[i] == 'E') {
                w += 1;
            }
            else if (s[i] == 'W') {
                w -= 1;
            }

            if (h > pow(10,9)) h = 1;
            if (h < 1) h = pow(10,9);
            if (w > pow(10,9)) w = 1;
            if (w < 1) w = pow(10,9);
        }

        cout << "Case #" << kase << ": " << w << " " << h << endl;
    }
}
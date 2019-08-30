class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        string str = "", ret = "";
        for (int i = 0; i < S.length(); i++) {
            str += S[i];
            if (S[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }
            if (cnt == 0) {
                ret += str.substr(1, str.length()-2);
                str = "";
            }
        }
        return ret;
    }
};
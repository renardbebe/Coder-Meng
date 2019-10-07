class Solution {
public:
    string reverseword(string s) {
        string ret = "";
        for (int i = s.length()-1; i >= 0; i--) {
            ret += s[i];
        }
        return ret;
    }
    
    string reverseWords(string s) {
        string tmp = "", ret = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                ret += reverseword(tmp);
                ret += " ";
                tmp = "";
            }
            else if (i == s.length()-1) {
                tmp += s[i];
                ret += reverseword(tmp);
            }
            else {
                tmp += s[i];
            }
        }
        return ret;
    }
};
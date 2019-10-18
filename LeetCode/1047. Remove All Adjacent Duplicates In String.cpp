class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> str;
        for (int i = 0; i < S.length(); i++) {
            if (str.size() && str.top() == S[i]) {
                str.pop();
            }
            else str.push(S[i]);
        }
        string ret = "";
        while (str.size()) {
            ret = str.top() + ret;
            str.pop();
        }
        return ret;
    }
};
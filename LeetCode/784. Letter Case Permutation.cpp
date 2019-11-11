class Solution {
public:
    vector<string> ret;
    void dfs (string s, int pos) {
        if (pos == s.length()) {
            ret.push_back(s);
            return;
        }
        if (s[pos] >= '0' && s[pos] <= '9') {
            dfs(s, pos+1);
        }
        else {
            if (s[pos] >= 'a' && s[pos] <= 'z') {
                dfs(s, pos+1);
                s[pos] += ('A' - 'a');
                dfs(s, pos+1);
                s[pos] -= ('A' - 'a');
            }
            else {
                dfs(s, pos+1);
                s[pos] -= ('A' - 'a');
                dfs(s, pos+1);
                s[pos] += ('A' - 'a');
            }
        }
        return;
    }
    vector<string> letterCasePermutation(string S) {
        ret.clear();
        dfs(S, 0);
        return ret;
    }
};
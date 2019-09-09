class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.length();
        vector<int> ret, a, b;
        for (int i = 0; i <= len; i++) {  // [0...N]
            a.push_back(i);
        }
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (S[i] == 'I') {
                ret.push_back(a[pos++]);
            }
            else {
                ret.push_back(a.back());
                a.pop_back();
            }
        }
        ret.push_back(a.back());
        return ret;
    }
};
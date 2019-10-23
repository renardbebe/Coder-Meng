class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> cnt;
        vector<string> ret;
        string tmp = "";
        for (int i = 0; i < A.length(); i++) {
            if (A[i] == ' ') {
                cnt[tmp] += 1;
                tmp = "";
            }
            else tmp += A[i];
        }
        if (tmp != "") cnt[tmp] += 1;
        
        tmp = "";
        for (int i = 0; i < B.length(); i++) {
            if (B[i] == ' ') {
                cnt[tmp] += 1;
                tmp = "";
            }
            else tmp += B[i];
        }
        if (tmp != "") cnt[tmp] += 1;
        
        for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second == 1) ret.push_back(it->first);
        }
        
        return ret;
    }
};
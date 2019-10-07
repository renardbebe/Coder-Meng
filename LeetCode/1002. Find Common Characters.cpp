#include <algorithm>
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ret;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int minn = 0xffffff;
            for (int j = 0; j < A.size(); j++) {
                int times = count(A[j].begin(), A[j].end(), ch);
                minn = min(minn, times);
            }
            for (int num = minn; num > 0; num--) {
                string str = "";
                str += ch;
                ret.push_back(str);
            }
        }
        return ret;
    }
};
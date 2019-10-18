class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ret;
        int sumLen = 0, lines = 1, lastWid = 0;
        for (int i = 0; i < S.length();) {
            sumLen += widths[S[i] - 'a'];
            if (sumLen <= 100) {
                i++;
            }
            else {
                lines += 1;
                sumLen = 0;
            }
        }
        ret.push_back(lines);
        ret.push_back(sumLen);
        return ret;
    }
};
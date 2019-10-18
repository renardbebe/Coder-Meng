class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rown = A.size();
        int coln = A[0].size();
        
        vector<vector<int>> ret;
        ret.resize(coln);
        for (int i = 0; i < coln; i++) {
            ret[i].resize(rown);
        }
        
        for (int i = 0; i < coln; i++) {
            for (int j = 0; j < rown; j++) {
                ret[i][j] = A[j][i];
            }
        }
        return ret;
    }
};
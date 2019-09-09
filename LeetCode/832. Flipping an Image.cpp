class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ret(A);
        for (int i = 0; i < A.size(); i++) {
            ret[i].clear();
            for (int j = A[i].size()-1; j >= 0; j--) {
                ret[i].push_back(1 - A[i][j]);
            }
        }
        return ret;
    }
};
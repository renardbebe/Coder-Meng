class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ret;
        for (int m = 0; m < r; m++) {
            vector<int> tmp;
            for (int n = 0; n < c; n++) {
                tmp.push_back(0);
            }
            ret.push_back(tmp);
        }
        int row = nums.size(), col = nums[0].size();
        if (r*c != row*col) return nums;
            
        int i = 0, j = 0;
        for (int m = 0; m < r; m++) {
            for (int n = 0; n < c; n++) {
                ret[m][n] = nums[i][j];
                if (j == col - 1) {
                    i += 1;
                    j = 0;
                }
                else j++;
            }
        }
        return ret;
    }
};
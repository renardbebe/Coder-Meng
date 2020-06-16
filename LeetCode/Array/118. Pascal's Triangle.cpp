class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; i++) {
            int size = i + 1;
            vector<int> level(size, 0);
            level[0] = 1;
            if (i) {
                level[size-1] = 1;
                for (int j = 1; j < size-1; j++) {
                    level[j] = ret[i-1][j-1] + ret[i-1][j];
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};
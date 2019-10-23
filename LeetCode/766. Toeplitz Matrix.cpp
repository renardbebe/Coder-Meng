class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int cur = 1; cur <= col; cur++) {
            int i = 0, j = col - cur;
            int num = matrix[i][j];
            while (i < row && j < col) {
                if (matrix[i][j] != num) {
                    return false;
                }
                else {
                    i++, j++;
                }
            }
        }
        
        for (int cur = 2; cur <= row; cur++) {
            int i = cur - 1, j = 0;
            int num = matrix[i][j];
            while (i < row && j < col) {
                if (matrix[i][j] != num) {
                    return false;
                }
                else {
                    i++, j++;
                }
            }
        }
        return true;
    }
};
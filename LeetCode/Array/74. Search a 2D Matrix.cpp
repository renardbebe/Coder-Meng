class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rown = matrix.size();
        if (rown == 0) return false;
        int coln = matrix[0].size();
        if (coln == 0) return false;
        
        int row = 0;
        for (int i = 0; i < rown; i++) {
            if (matrix[i][0] <= target) {
                if (i == rown - 1) {
                    row = i;
                }
                else {
                    if (matrix[i+1][0] > target) {
                        row = i;
                        break;
                    }
                }
            }
        }
        
        int left = 0, right = matrix[row].size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            cout << left << " " << mid << " " << right << endl;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left == right && matrix[row][left] == target) return true;
        return false;
    }
};
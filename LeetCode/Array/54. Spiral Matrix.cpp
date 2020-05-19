class Solution {
private:
    bool in (int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    
    void travel(vector<vector<int>> matrix, vector<int>& ret, int row, int col) {
        
        int i = 0, j = 0, dir = 0;
        ret.push_back(matrix[0][0]);
        
        int next_x, next_y;
        while (ret.size() < row * col) {
            if (dir == 0) {  // right
                next_x = i, next_y = j + 1;
            }
            else if (dir == 1) {  // down
                next_x = i + 1, next_y = j;
            }
            else if (dir == 2) {  // left
                next_x = i, next_y = j - 1;
            }
            else {  // up
                 next_x = i - 1, next_y = j;
            }
            
            if (in(next_x, next_y, row, col) && 
                find(ret.begin(), ret.end(), matrix[next_x][next_y]) == ret.end()) {
                ret.push_back(matrix[next_x][next_y]);
                i = next_x, j = next_y;
            }
            else {  // change direction
                dir = (dir + 1) % 4;
            }
            
        }
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (!matrix.empty()) {
            int row = matrix.size(), col = matrix[0].size();
            travel(matrix, ret, row, col);
        }
        return ret;
    }
};
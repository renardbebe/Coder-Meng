class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0, front = 0, side = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            int max_row = 0;
            for (int j = 0; j < cols; j++) {
                if(grid[i][j]) top += 1;
                max_row = max(max_row, grid[i][j]);
            }
            front += max_row;
        }
        for (int j = 0; j < cols; j++) {
            int max_col = 0;
            for (int i = 0; i < rows; i++) {
                max_col = max(max_col, grid[i][j]);
            }
            side += max_col;
        }
        return (top + front + side);
    }
};
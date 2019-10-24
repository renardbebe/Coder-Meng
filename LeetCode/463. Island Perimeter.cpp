class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if ((i-1) >= 0 && grid[i-1][j] == 0) sum += 1;
                    if ((i+1) < row && grid[i+1][j] == 0) sum += 1;
                    if ((j-1) >= 0 && grid[i][j-1] == 0) sum += 1;
                    if ((j+1) < col && grid[i][j+1] == 0) sum += 1;
                    
                    // on the edge
                    if (i == 0) sum += 1;
                    if (i == row-1) sum += 1;
                    if (j == 0) sum += 1;
                    if (j == col-1) sum += 1;
                }
            }
        }
        return sum;
    }
};
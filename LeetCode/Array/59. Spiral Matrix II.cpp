class Solution {
private:
    bool in (int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    
    void travel(vector<vector<int>>& matrix, int cur, int n) {
        
        int i = 0, j = 0, dir = 0;
        matrix[0][0] = cur++;
        
        int next_x, next_y;
        while (cur <= n * n) {
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
            
            if (in(next_x, next_y, n) && 
                matrix[next_x][next_y] == 0) {
                matrix[next_x][next_y] = cur++;
                i = next_x, j = next_y;
            }
            else {  // change direction
                dir = (dir + 1) % 4;
            }
            
        }
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         matrix[i][j] = 0;
        // }
        travel(matrix, 1, n);
        return matrix;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9], col[9], cell[9];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char num = board[i][j];
                if (num == '.') continue;
                
                int cell_id = 3 * (i/3) + j/3;
                if ( row[i].count(num) || 
                     col[j].count(num) || 
                     cell[cell_id].count(num) ) {
                    return false;
                }
                
                row[i].insert(num);
                col[j].insert(num);
                cell[cell_id].insert(num);
            }
        }
        return true;
    }
};
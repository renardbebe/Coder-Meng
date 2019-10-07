class Solution {
public:
    int cnt = 0;
    int next_[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs (int x, int y, vector<vector<char>>& board, int dir) {
        if (x < 0 || x > 7 || y < 0 || y > 7) return;
        char ch = board[x][y];
        if (ch == 'B') return;
        if (ch == 'p') {
            cnt++;
            return;
        }
        dfs(x + next_[dir][0], y + next_[dir][1], board, dir);
    }
    
    int numRookCaptures(vector<vector<char>>& board) {
        bool find = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    find = true;
                    for (int dir = 0; dir < 4; dir++) {
                        dfs(i, j, board, dir);
                    }
                    break;
                }
            }
            if (find) break;
        }
        return cnt;
    }
};
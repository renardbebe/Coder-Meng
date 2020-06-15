class Solution {
private:
    bool in(int r, int c, int rown, int coln) {
        return (r >= 0 && r < rown && c >= 0 && c < coln);
    }
    
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool dfs(int i, int j, int rown, int coln, vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return true;
        }
        
        char ori = board[i][j];
        board[i][j] = '*';
        char ch = word[0];
        for (int dir = 0; dir < 4; dir++) {
            int next_r = i + dirs[dir][0];
            int next_c = j + dirs[dir][1];
            if (in(next_r, next_c, rown, coln) && board[next_r][next_c] == ch) {
                string subword = word.substr(1);
                bool flag = dfs(next_r, next_c, rown, coln, board, subword);
                if (flag) return true;
            }
        }
        board[i][j] = ori;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rown = board.size();
        int coln = board[0].size();
        char ch = word[0];
        for (int i = 0; i < rown; i++) {
            for (int j = 0; j < coln; j++) {
                if (board[i][j] == ch) {
                    string subword = word.substr(1);
                    bool flag = dfs(i, j, rown, coln, board, subword);
                    if (flag) return true;
                }
            }
        }
        return false;
    }
};
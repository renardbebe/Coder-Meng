class Solution {
public:
    bool judgeCircle(string moves) {
//                      Right     Left     Up      Down
        int to[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int len = moves.length(), x = 0, y = 0;
        for (int i = 0; i < len; i++) {
            if (moves[i] == 'R') {
                x += to[0][0];
                y += to[0][1];
            }
            else if (moves[i] == 'L') {
                x += to[1][0];
                y += to[1][1];
            }
            else if (moves[i] == 'U') {
                x += to[2][0];
                y += to[2][1];
            }
            else if (moves[i] == 'D') {
                x += to[3][0];
                y += to[3][1];
            }
        }
        if (x == 0 && y == 0) return true;
        else return false;
    }
};
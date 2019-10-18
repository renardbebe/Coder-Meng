class Solution {
public:
    struct Point {
        int x;
        int y;
        int dis;
        Point() {}
        Point(int x_, int y_) {
            x = x_;
            y = y_;
        }
        bool operator < (const Point &a) const {
            return (dis < a.dis);
        }
    };
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        vector<Point> all;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                Point p(i, j);
                p.dis = (abs(i - r0) + abs(j - c0));
                all.push_back(p);
            }
        }
        sort(all.begin(), all.end());
        for (int i = 0; i < all.size(); i++) {
            vector<int> tmp;
            tmp.push_back(all[i].x);
            tmp.push_back(all[i].y);
            ret.push_back(tmp);
        }
        return ret;
    }
};
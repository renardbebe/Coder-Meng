#include <iostream>
using namespace std;

// TLE

int W, H, L, U, R, D;
float prop;
int pass, total;

void dfs (int x, int y, float p) {
    if (x == W && y == H) {
        prop += p;
        return;
    }
    if (x >= L && x <= R && y >= U && y <= D) {
        return;
    }
    
    int next_x, next_y;
    if (x == W) {
        next_x = x;
        next_y = y + 1;
        dfs(next_x, next_y, 1.0*p);
    }
    else if (y == H) {
        next_x = x + 1;
        next_y = y;
        dfs(next_x, next_y, 1.0*p);
    }
    else {
        next_x = x + 1;
        next_y = y;
        dfs(next_x, next_y, 0.5*p);
        next_x = x;
        next_y = y + 1;
        dfs(next_x, next_y, 0.5*p);
    }
    total += 1;
}

int main () {
    int T;
    cin >> T;

    for (int kase = 1; kase <= T; kase++) {
        cin >> W >> H >> L >> U >> R >> D;
        prop = 0.0;

        dfs(1, 1, 1.0);
        cout << "Case #" << kase << ": " << prop << endl;
    }
}
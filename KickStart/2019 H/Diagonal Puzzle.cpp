#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 105
char puzzle[MAXN][MAXN];
int visit[4 * MAXN - 2];
int moves, N;

inline bool ok () {
    char ch = puzzle[1][1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (puzzle[i][j] != ch) return false;
        }
    }
    return true;
}

inline char op (char ch) {
    if (ch == '.') return '#';
    else return '.';
}

inline void flip (int line) {
    if (line <= N) {
        for (int i = 1; i <= line; i++) {
            int j = line - i + 1;
            puzzle[i][j] = op(puzzle[i][j]);
        }
    }
    else if (line <= (2 * N - 1)) {
        int cnt = 2 * N - line;  // 执行次数
        while(cnt) {
            int i = N;
            int j = line - i + 1;
            puzzle[i][j] = op(puzzle[i][j]);
            i--;
            cnt--;
        }
    }
    else if (line <= (3 * N - 1)) {
        int cnt = line - 2 * N + 1;
        int m = cnt;
        while(cnt) {
            int i = 1;
            int j = i + m;
            puzzle[i][j] = op(puzzle[i][j]);
            i++;
            cnt--;
        }
    }
    else {
        int cnt = line - 3 * N + 1;
        while(cnt) {
            int i = N;
            int j = i - (N - cnt);
            puzzle[i][j] = op(puzzle[i][j]);
            i--;
            cnt--;
        }
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << puzzle[i][j];
        }
        cout << endl;
    }
}

void dfs (int lines, int step) {
    cout << step << endl;
    print();
    
    if (ok()) {
        moves = min(moves, step);
        return;
    }

    for (int l = 1; l <= lines; l++) {
        if (!visit[l]) {
            flip(l);
            visit[l] = 1;
            dfs(lines, step+1);

            flip(l);
            visit[l] = 0;
            dfs(lines, step);
        }
    }
}

int main () {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> N;
        memset(puzzle, ' ', sizeof(puzzle));
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> puzzle[i][j];
            }
        }
        moves = 0xffffff;
        int lines = 4 * N - 2;  // diag lines number
        dfs(lines, 0);
        cout << "Case #" << kase << ": " << moves << endl;
    }
}
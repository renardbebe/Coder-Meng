#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1010
long long X[MAXN];

int main () {
    int T, N;
    long long D;
    cin >> T;

    for (int kase = 1; kase <= T; kase++) {
        cin >> N >> D;
        for (int i = 1; i <= N; i++) {
            cin >> X[i];
        }

        long long lastday = D;
        for (int i = N; i >= 1; i--) {
            long long multi = lastday / X[i];
            lastday = multi * X[i];
        }
        
        cout << "Case #" << kase << ": " << lastday << endl;
    }
}
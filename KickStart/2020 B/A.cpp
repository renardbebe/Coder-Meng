#include <iostream>
using namespace std;

#define MAXN 110
int height[MAXN];

int main () {
    int T, num, N;
    cin >> T;
    num = 0;

    for (int kase = 1; kase <= T; kase++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> height[i];
        }
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == (N-1)) continue;
            if (height[i] > height[i-1] && height[i] > height[i+1]) {
                num++;
            }
            
        }
        
        cout << "Case #" << kase << ": " << num << endl;
    }
}
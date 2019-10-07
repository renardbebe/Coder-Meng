class Solution {
public:
    int F[35];
    int fib(int N) {
        F[0] = 0;
        F[1] = 1;
        for (int i = 2; i <= 30; i++) {
            F[i] = F[i-1] + F[i-2];
        }
        return F[N];
    }
};
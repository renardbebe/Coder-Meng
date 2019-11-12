class Solution {
public:
    int T[50];
    void init () {
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        for (int i = 3; i <= 37; i++) 
            T[i] = T[i-1] + T[i-2] + T[i-3];
    }
    
    int tribonacci(int n) {
        init();
        return T[n];
    }
};
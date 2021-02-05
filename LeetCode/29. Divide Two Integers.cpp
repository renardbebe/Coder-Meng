class Solution {
public:
    int divide(int dividend, int divisor) {
        // INT_MAX = 2^31 − 1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        else return int(dividend / divisor);
    }
};
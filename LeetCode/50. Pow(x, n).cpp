class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1.0;
        bool reverse = false;
        if (n < 0) {
            reverse = true;
            n *= -1;
        }
        
        while (n > 0) {
            if (n % 2) {
                n--;
                ans *= x;
            }
            else {
                n /= 2;
                x *= x;
            }
        }
        
        if (reverse) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};
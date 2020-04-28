class Solution {
public:
    inline int cal (int n) {
        int h = 0;
        while (n) {
            h += n % 10;
            n /= 10;
        }
        return h;
    }
    
    int addDigits(int num) {
        while (num > 9) {
            num = cal(num);
        }
        return num;
    }
};
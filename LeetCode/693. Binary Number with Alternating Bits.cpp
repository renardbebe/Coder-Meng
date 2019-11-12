class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        if (!n) return true;
        while (n) {
            int bit = n % 2;
            if (bit == last) return false;
            last = bit;
            n /= 2;
        }
        return true;
    }
};
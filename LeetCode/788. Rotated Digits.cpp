class Solution {
public:    
    inline bool valid (int n) {  // n >= 1
        bool diff = false;
        while (n) {
            int h = n % 10;
            if (h == 6 || h == 9 || h == 2 || h == 5) diff = true;
            if (h == 3 || h == 4 || h == 7) return false;
            n /= 10;
        }
        if(diff) return true;
        else return false;
    }
    
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (valid(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};
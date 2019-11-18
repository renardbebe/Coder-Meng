class Solution {
public:
    bool canWinNim(int n) {
        int h = n % 4;
        if (h == 0 || h == 4) return false;
        else return true;
    }
};
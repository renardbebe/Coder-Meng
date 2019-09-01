class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            int x = i, num = 0;
            bool flag = true;
            while (x) {
                num = x % 10;
                if (num == 0 || (num && i % num != 0)) {
                    flag = false;
                    break;
                }
                x /= 10;
            }
            if (flag) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
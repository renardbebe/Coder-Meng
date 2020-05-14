class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        bool curin = false;
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                curin = true;
            }
            else {
                digits[i] += 1;
                curin = false;
                break;
            }
        }
        if (curin) digits.insert(digits.begin(), 1);
        return digits;
    }
};
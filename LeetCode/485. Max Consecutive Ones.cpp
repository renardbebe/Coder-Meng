class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> zero;
        int lastpos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero.push_back(i - lastpos - 1);
                lastpos = i;
            }
        }
        if (lastpos != nums.size() - 1) {
            zero.push_back(nums.size() - lastpos - 1);
        }
        sort(zero.begin(), zero.end());
        return zero[zero.size()-1];
    }
};
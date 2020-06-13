class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return false;
        
        sort(nums.begin(), nums.end());
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};
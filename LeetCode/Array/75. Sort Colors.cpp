class Solution {
public:
    void sortColors(vector<int>& nums) {
        int firstIdx = 0, lastIdx = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            // 顺序很重要！
            while (nums[i] == 2 && i < lastIdx) swap(nums[i], nums[lastIdx--]);
            while (nums[i] == 0 && i > firstIdx) swap(nums[i], nums[firstIdx++]);
        }
    }
};
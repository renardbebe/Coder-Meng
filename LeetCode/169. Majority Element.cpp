class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.push_back(0);
        int lastpos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[lastpos]) {
                continue;
            }
            int times = i - lastpos;
            if (times > floor(n / 2)) return nums[lastpos];
            lastpos = i;
        }
        return 0;
    }
};
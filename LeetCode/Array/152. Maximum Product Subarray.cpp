class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], max_so_far = nums[0], min_so_far = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int cur_maxp = max_so_far;
            // record the max product till now
            max_so_far = max(cur_maxp * nums[i], min_so_far * nums[i]);
            max_so_far = max(max_so_far, nums[i]);
            // record the min product till now
            min_so_far = min(cur_maxp * nums[i], min_so_far * nums[i]);
            min_so_far = min(min_so_far, nums[i]);
            
            maxp = max(maxp, max_so_far);
        }
        return maxp;
    }
};
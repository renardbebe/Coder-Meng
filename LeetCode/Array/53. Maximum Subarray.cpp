class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* *****************************
        // O(n^2) solution
        int maxn = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = nums[i];
            maxn = max(maxn, sum);
            for (int j = i+1; j < nums.size(); j++) {
                sum += nums[j];
                maxn = max(maxn, sum);
            }
        }
        return maxn;
        ***************************** */
        
        // O(n) solution
        int n = nums.size();
        int maxn = nums[0];
        int sum[n];  // 记录以i为结尾的子串的最大和
        memset(sum, 0 ,sizeof(sum));
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = max(nums[i], sum[i-1] + nums[i]);
            maxn = max(maxn, sum[i]);
        }
        return maxn;
    }
};

/* *****************************
// divide and conquer approach
        
***************************** */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
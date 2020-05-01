class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n < 4)  return ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // check the min_sum and max_sum of all possible combinations
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                // check the min_sum and max_sum of all possible combinations
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;

                int front = j + 1, back = n - 1;
                while (front < back) {
                    int sum = nums[i] + nums[j] + nums[front] + nums[back];
                    if (sum < target) front++;
                    else if (sum > target) back--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        ret.push_back(quadruplet);
                        while (front < back && nums[front] == quadruplet[2]) front++;
                        while (front < back && nums[back] == quadruplet[3]) back--;
                    }
                }
            }
        }
        return ret;
    }
};
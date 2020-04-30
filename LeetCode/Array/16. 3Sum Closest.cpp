class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minn = 0xffffff;
        for (int i = 0; i < nums.size(); i++) {
            int front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (abs(target - sum) < abs(target - minn)) {
                    minn = sum;
                }
                
                if (sum < target) front++;
                else back--;
            }
        }
        return minn;
    }
};
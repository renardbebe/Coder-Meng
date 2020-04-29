class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                cnt++;
                j--;
            }
            else i++;
        }
        return nums.size() - cnt;
    }
};
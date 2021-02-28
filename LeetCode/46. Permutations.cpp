class Solution {
private:
    vector<vector<int> > ans;

	void find(vector<int>& nums, int i, int n) {
		if (i == n) {
			ans.push_back(nums);
			return;
		}
		for (int j = i; j < n; j++) {
			swap(nums[i], nums[j]);
			find(nums, i+1, n);
			swap(nums[i], nums[j]);
		}
	}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        find(nums, 0, n);
        return ans;
    }
};
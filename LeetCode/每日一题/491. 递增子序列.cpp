class Solution {
private:
    void dfs(vector<int> nums, int i, vector<int>& sub, set<vector<int>>& res) {
        if (sub.size() >= 2) {  // 每次在这里使用 find() 来去重会超时
            res.insert(sub);
        }

        for (int j = i; j < nums.size(); j++) {
            if (sub.empty() || (nums[j] >= sub.back())) {
                sub.push_back(nums[j]);
                dfs(nums, j + 1, sub, res);
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;  // remove duplication
        vector<int> sub;
        dfs(nums, 0, sub, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
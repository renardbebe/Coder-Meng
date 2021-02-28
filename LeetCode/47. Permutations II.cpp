class Solution {
private:
    vector<vector<int> > ans;
    set<string> cnt;
    
    void find(vector<int>& nums, string& tmp, int i, int n) {
        if (i == n) {
            if (cnt.count(tmp)) return;
            ans.push_back(nums);
            cnt.insert(tmp);
        }
        
        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            tmp.push_back(nums[i]);
            find(nums, tmp, i+1, n);
            swap(nums[j], nums[i]);
            tmp.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        string tmp = "";
        find(nums, tmp, 0, n);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> em;
        ret.push_back(em);
        for (int i = 0; i < nums.size(); i++) {
            int len = ret.size();
            for (int j = 0; j < len; j++) {
                vector<int> sub = ret[j];
                sub.push_back(nums[i]);
                sort(sub.begin(), sub.end());
                ret.push_back(sub);
            }
        }
        set<vector<int>> dup(ret.begin(), ret.end());
        ret.assign(dup.begin(), dup.end());
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> em;
        ret.push_back(em);
        for (int i = 0; i < nums.size(); i++) {
            int len = ret.size();
            for (int j = 0; j < len; j++) {
                vector<int> sub = ret[j];
                sub.push_back(nums[i]);
                ret.push_back(sub);
            }
        }
        return ret;
    }
};
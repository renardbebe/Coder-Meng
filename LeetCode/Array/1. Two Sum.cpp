class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (index.find(complement) != index.end()) {
                ret.push_back(index[complement]);
                ret.push_back(i);
                break;
            }
            else {
                index[nums[i]] = i;
            }
        }
        return ret;
    }
};
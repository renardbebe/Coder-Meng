class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curNum = 1;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < curNum) {
                continue;
            }
            else if (nums[i] > curNum) {
                ret.push_back(curNum);
                curNum++;
                i--;
            }
            else curNum++;
        }
        while (curNum <= nums.size()) {
            ret.push_back(curNum);
            curNum++;
        }
        return ret;
    }
};
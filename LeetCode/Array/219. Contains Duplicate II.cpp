class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> pos;
        for (int i = 0; i < len; i++) {
            if (pos.find(nums[i]) != pos.end()) {  // has appeared in map
                int lastpos = pos[nums[i]];
                if (abs(i - lastpos) <= k) return true;
            }
            pos[nums[i]] = i;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int low = 0, high = nums.size() - 1, mid = -1;
        bool find = false;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                find = true;
                break;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (!find) {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else {
            int start_pos = mid, end_pos = mid;
            while (start_pos-1 >= 0) {
                if (nums[start_pos-1] == target) start_pos--;
                else break;
            }
            while (end_pos+1 < nums.size()) {
                if (nums[end_pos+1] == target) end_pos++;
                else break;
            }
            ret.push_back(start_pos);
            ret.push_back(end_pos);
        }
        return ret;
    }
};
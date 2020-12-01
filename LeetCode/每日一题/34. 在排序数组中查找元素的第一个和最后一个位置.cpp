class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int start_pos = -1, end_pos = -1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                start_pos = mid;
                while (start_pos >= 0 && nums[start_pos] == target) {
                    start_pos--;
                }
                start_pos++;

                end_pos = mid;
                while (end_pos < nums.size() && nums[end_pos] == target) {
                    end_pos++;
                }
                end_pos--;
                break;
            }
        }
        vector<int> ret;
        ret.push_back(start_pos);
        ret.push_back(end_pos);
        return ret;
    }
};
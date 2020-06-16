class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int k = 0; k < nums.size(); k++) {
            if (i < 2 || nums[k] > nums[i-2])
                nums[i++] = nums[k];
        }
        return i;
    }
};

/* This solution can be easily generalized to "at most K duplicates" */

/*
int removeDuplicates(vector<int>& nums, int k) {
    int i = 0;
    for (int n : nums)
        if (i < k || n > nums[i-k])
            nums[i++] = n;
    return i;
}
*/
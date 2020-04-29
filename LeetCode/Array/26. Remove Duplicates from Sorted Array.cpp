class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) 
            return nums.size();
        int cnt = 0, oriSize = nums.size();
        int lastNum = nums[0];
        for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); it++) {
            if (*it == lastNum) {
                nums.erase(it);
                cnt++;
                it--;
            }
            else lastNum = *it;
        }
        return oriSize - cnt;
    }
};
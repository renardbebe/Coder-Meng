class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        // for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        //     if (*it == 0) {
        //         cnt++;
        //         nums.erase(it);
        //     }
        // }
        for (int i = 0; i < nums.size();) {
            if (nums[i] == 0) {
                cnt++;
                nums.erase(nums.begin()+i);
            }
            else i++;
        }
        while(cnt) {
            nums.push_back(0);
            cnt--;
        }
    }
};
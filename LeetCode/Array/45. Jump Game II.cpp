class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        int step = 0;
        int curMaxPos = 0, oneStepMaxPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            curMaxPos = max(curMaxPos, i + nums[i]);
            
            if (i == oneStepMaxPos && i != nums.size() - 1) {
                oneStepMaxPos = curMaxPos;
                step++;
            }
        }
        return step;
    }
};
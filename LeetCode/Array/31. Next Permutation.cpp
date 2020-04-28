// 先找到从后向前数，第一个降序的位置，把此位置后面的翻转。再把这个降序数字和后面第一个比它大的位置交换。
// 12431 → 翻转431 → 12134 → 交换2和3 → 13124

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 找到自然顺序下的下一个全排列
        int len = nums.size();
        int startPos = len-1, endPos = len-1, firstPos = 0;
        for (int i = endPos-1; i >= 0; i--) {
            if (nums[i+1] <= nums[i]) {
                startPos = i;
            }
            else break;
        }
        
        // reverse decreasing part
        int j = endPos;
        for (int i = startPos; i <= j; i++) {
            swap(nums[i], nums[j]);
            j--;
        }
        
        if(startPos > 0) {
            int desNum = nums[startPos-1];
            for (int i = startPos; i <= endPos; i++) {
                if (desNum < nums[i]) {
                    firstPos = i;
                    break;
                }
            }
            swap(nums[startPos-1], nums[firstPos]);
        }
    }
};
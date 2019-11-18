class Solution {
public:
    bool isMonotonic(vector<int>& A) {  // 判断数组是不是递增或递减
        bool isUp = true, isDown = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i-1] > A[i]) isUp = false;
            if (A[i-1] < A[i]) isDown = false;
        }
        return (isUp || isDown);
    }
};
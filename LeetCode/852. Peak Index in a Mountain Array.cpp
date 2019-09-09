class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int ret = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > A[i+1]) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};
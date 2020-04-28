class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i = 0; i < A.size(); i++) sum += A[i];
        sum /= 3;
        int subsum = 0, cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (subsum != sum) {
                subsum += A[i];
            }
            if (subsum == sum) {
                subsum = 0;
                cnt++;
            }
        }
        if(cnt == 3) return true;
        else return false;
    }
};
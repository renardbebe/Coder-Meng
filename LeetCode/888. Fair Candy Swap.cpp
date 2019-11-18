class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ret;
        int a = 0, b = 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < A.size(); i++) {
            sum1 += A[i];
        }
        for (int i = 0; i < B.size(); i++) {
            sum2 += B[i];
        }
        int sum = (sum1 + sum2) / 2;
        bool find = false;
        for (int i = 0; i < A.size() && !find; i++) {
            for (int j = 0; j < B.size() && !find; j++) {
                if ((sum - sum1 + A[i]) == B[j]) {
                    a = A[i];
                    b = B[j];
                    find = true;
                }
            }
        }
        
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};
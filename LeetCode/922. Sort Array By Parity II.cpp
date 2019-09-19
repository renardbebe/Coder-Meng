class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ret, odd, even;
        int len = A.size();
        for (int i = 0; i < len; i++) {
            if (A[i] % 2 == 0) {
                even.push_back(A[i]);
            }
            else odd.push_back(A[i]);
        }
        for (int i = 0; i < len/2; i++) {
            ret.push_back(even[i]);
            ret.push_back(odd[i]);
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int times = A.size();
        int sum = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] % 2 == 0) sum += A[j];
        }
        
        vector<int> ret;
        for (int i = 0; i < times; i++) {
            int val = queries[i][0];
            int idx = queries[i][1];
            A[idx] += val;
            
            if ((abs(A[idx] - val) % 2 != 0) && (abs(A[idx]) % 2 == 0)) {
                sum += A[idx];
            }
            else if ((abs(A[idx] - val) % 2 == 0) && (abs(A[idx]) % 2 == 0)) {
                sum += val;
            }
            else if ((abs(A[idx] - val) % 2 == 0) && (abs(A[idx]) % 2 != 0)) {
                sum -= (A[idx] - val);
            }
            ret.push_back(sum);
        }
        return ret;
    }
};
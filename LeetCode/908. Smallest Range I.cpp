class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int minn = A[0], maxn = A[A.size()-1];
        minn += K;
        maxn -= K;
        if (minn >= maxn) return 0;
        else return (maxn - minn);
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        // 'Bottom-up' DP
        for (int layer = n-2; layer >= 0; layer--) {
            for (int i = 0; i <= layer; i++) {
                /*
                For the bottom to the top, for the i-th element in k-th layer:
                    minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i]
                Since the row minpath[k+1] would be useless after minpath[k] is computed, we can simply set minpath as a 1D array, and iteratively update itself:
                For the k-th level:
                    minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i]; 
                */
                dp[i] = min(dp[i], dp[i+1]) + triangle[layer][i];
            }
        }
        return dp[0];
    }
};
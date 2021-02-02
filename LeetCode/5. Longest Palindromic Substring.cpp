class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), maxLen = 1;
        bool dp[len][len];
        memset(dp, 0, sizeof(dp));
        
        string ans = "";
        int start_pos = 0;
        // dp
        for (int i = 0; i < len; i++) dp[i][i] = true;
        for (int i = 0; i < len; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start_pos = i;
                maxLen = 2;
            }
        }
        
        // Check for substring length greater than 2.
        for (int k = 3; k <= len; k++) {
            for (int i = 0; i+k-1 < len; i++) {
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (k > maxLen) {
                        maxLen = k;
                        start_pos = i;
                    }
                }
            }
        }
        
        for (int i = start_pos; maxLen > 0; i++) {
            ans += s[i];
            maxLen--;
        }
        return ans;
    }
};
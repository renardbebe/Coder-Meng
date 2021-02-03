class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= 1 || numRows == 1) return s;
        
        map<int, vector<char> > matrix;
        int mod = 2 * (numRows - 1);
        for (int i = 0; i < s.length(); i++) {
            int j = i % mod;
            if (j > numRows - 1) 
                j = mod - j;
            matrix[j].push_back(s[i]);
        }
        
        string ans = "";
        for (int i = 0; i <= numRows; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
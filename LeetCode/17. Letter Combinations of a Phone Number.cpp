class Solution {
private:
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "prqs", "tuv", "wxyz"};
    
    void dfs(int index, string tmp, string digits, vector<string>& ans) {
        if (index == digits.length()) {
            ans.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < letter[digits[index] - '0'].length(); i++) {
            tmp.push_back(letter[digits[index] - '0'][i]);
            dfs(index+1, tmp, digits, ans);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
         
        vector<string> ans;
        dfs(0, "", digits, ans);
        return ans;
    }
};
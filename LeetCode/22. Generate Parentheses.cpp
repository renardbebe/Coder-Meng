class Solution {
private:
    void makePair(int left, int right, int n, string& tmp, vector<string>& ans) {
        if (left == n && right == n) {
            ans.push_back(tmp);
            return;
        }
        
        if (left <= n) {
            tmp.push_back('(');
            makePair(left+1, right, n, tmp, ans);
            tmp.pop_back();
        }
        if (right < left) {
            tmp.push_back(')');
            makePair(left, right+1, n, tmp, ans);
            tmp.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        makePair(0, 0, n, tmp, ans);
        return ans;
    }
};
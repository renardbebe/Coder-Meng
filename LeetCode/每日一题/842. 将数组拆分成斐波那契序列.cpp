class Solution {
public:
    // dfs, 回溯
    vector<int> ans;

    bool check() {
        if (ans.size() < 3) return true;
        else return ( (long long)ans[ans.size() - 1] == (long long)ans[ans.size() - 2] + (long long) ans[ans.size() - 3] );
    }

    bool dfs(string S, int ind) {
        if (ind >= S.length()) return ans.size() >= 3;

        if (S[ind] == '0') {  // 只能将这个0作为本层所选的数，不能向字符串后面枚举其他的数(否则有前导零)
            ans.push_back(0);
            if (check() && dfs(S, ind + 1)) return true;  // // 本次选择合法并且后续搜索也找到答案(剪枝)
            ans.pop_back();
            return false;  // 回溯
        }
        else {
            long long cur = 0;  // 枚举所有不超过INT_MAX的数作为本层选择
            while (ind < S.length()) {
                cur = cur * 10 + (S[ind] - '0');
                ind++;
                if (cur > INT_MAX) return false;
                ans.push_back(cur);
                if(check() && dfs(S, ind)) return true;
                ans.pop_back();
            }
            return false;
        }
    }

    vector<int> splitIntoFibonacci(string S) {
        if (dfs(S, 0)) return ans;
        else return {};
    }
};
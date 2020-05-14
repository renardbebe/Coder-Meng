class Solution {
private:
    void combinationSum(vector<int> candidates, int target, vector<vector<int>>& ret, vector<int>& combination, int begin) {
        if (target == 0) {
            if (find(ret.begin(), ret.end(), combination) == ret.end())
                ret.push_back(combination);
            return;
        }
        
        for (int i = begin; i < candidates.size(); i++) {
            if (target < candidates[i]) break;
            
            combination.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], ret, combination, i+1);
            combination.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // !!
        vector<vector<int>> ret;
        vector<int> combination;
        combinationSum(candidates, target, ret, combination, 0);
        return ret;
    }
};
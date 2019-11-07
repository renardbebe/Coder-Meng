/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<long long, long long> sum;
    map<long long, long long> node;
    void dfs (TreeNode* root, int dep) {
        if (root) {
            sum[dep] += root->val;
            node[dep] += 1;
            
            dfs(root->left, dep+1);
            dfs(root->right, dep+1);
        }
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        sum.clear();
        node.clear();
        dfs(root, 0);
        
        vector<double> avg;
        for (map<long long, long long>::iterator it = sum.begin(); it != sum.end(); it++) {
            avg.push_back(it->second * 1.0 / node[it->first]);
        }
        return avg;
    }
};
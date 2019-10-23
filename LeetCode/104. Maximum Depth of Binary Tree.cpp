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
    void dfs (TreeNode* root, int dep, int& maxDep) {
        if (root) {
            maxDep = max(dep, maxDep);
            dfs (root->left, dep+1, maxDep);
            dfs (root->right, dep+1, maxDep);
        }
        return;
    }
    
    int maxDepth(TreeNode* root) {
        int maxDep = 0;
        dfs(root, 0, maxDep);
        if(!root) return 0;
        else return maxDep + 1;
    }
};
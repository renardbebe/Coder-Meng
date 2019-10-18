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
    vector<int> path1;
    vector<int> path2;
    
    void dfs(TreeNode* root, vector<int>& path) {
        if (!root) return;
        if ((!root->left) && (!root->right)) {  // leaf node
            path.push_back(root->val);
        }
        else {
            dfs(root->left, path);
            dfs(root->right, path);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, path1);
        dfs(root2, path2);
        
        if (path1 == path2) return true;
        else return false;
    }
};
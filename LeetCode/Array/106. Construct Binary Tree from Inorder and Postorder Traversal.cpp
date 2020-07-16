/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if (ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        // find root pos in inorder list
        int rootPos = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == postorder[pe]) {
                rootPos = i;
                break;
            }
        }
        
        root->right = build(inorder, postorder, rootPos + 1, ie, pe - (ie - rootPos), pe - 1);
        root->left = build(inorder, postorder, is, rootPos - 1, ps, ps + (rootPos - is) - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
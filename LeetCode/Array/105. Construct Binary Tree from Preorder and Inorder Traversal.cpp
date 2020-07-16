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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[ps]);
        // find root pos in inorder list
        int rootPos = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == preorder[ps]) {
                rootPos = i;
                break;
            }
        }
        // Inorder: The first part contains (rootPos - is) elements, and the second part has (ie - pos) elements.
        // build left subtree
        root->left = build(preorder, inorder, ps + 1, ps + (rootPos - is), is, rootPos - 1);
        // build right subtree
        root->right = build(preorder, inorder, pe - (ie - rootPos - 1), pe, rootPos + 1, ie);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
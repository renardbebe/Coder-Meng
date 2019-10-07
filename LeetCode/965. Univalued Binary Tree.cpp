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
    int num = 0, first = 1;
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        if (first) {
            num = root->val;
            first = 0;
        }
        if (root->val == num) {
            if (isUnivalTree(root->left) && isUnivalTree(root->right)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};
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
    int sum;
    int convert (vector<int> s) {
        int num = 0;
        int len = s.size();
        for (int i = len - 1; i >= 0; i--) {
            num += s[i] * pow(2, len - i - 1);
        }
        return num;
    }
    
    bool isleaf (TreeNode* root) {
        return (!root->left && !root->right);
    }
    
    void dfs (TreeNode* root, vector<int> vec) {
        if (root) {
            vec.push_back(root->val);
            if (isleaf(root)) {
                sum += convert(vec);
            }
            else {
                dfs(root->left, vec);
                dfs(root->right, vec);
            }
        }
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        vector<int> vec;
        dfs(root, vec);
        return sum;
    }
};
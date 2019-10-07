/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root != NULL) {
            int max_dep = 0, dep = 0;
            if (root->children.size()) {
                for (int i = 0; i < root->children.size(); i++) {
                    dep = maxDepth(root->children[i]);
                    max_dep = max(max_dep, dep+1);
                }
                return max_dep;
            }
            else {
                return 1;
            }
        }
        else {
            return 0;
        }
    }
};
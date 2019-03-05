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
    int depth(TreeNode* root, bool& balanced){
        if(root == NULL) return 0;
        int depthLeft = depth(root->left, balanced);
        int depthRight = depth(root->right, balanced);
        if(abs(depthLeft - depthRight) > 1)
            balanced = false;
        return max(1+depthLeft, 1+depthRight);
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        int d = depth(root, balanced);
        return balanced;
    }
};


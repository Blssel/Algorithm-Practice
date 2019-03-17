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
    void inOrder(TreeNode* root, long& lastNum, bool& res){
        if(res==false) return;
        if(root->left != NULL)
            inOrder(root->left, lastNum, res);
        long cur = root->val;
        if(cur<=lastNum){
            cout<<cur<<","<<lastNum<<endl;
            res = false;
        }
        lastNum = cur;
        if(root->right != NULL){
            inOrder(root->right, lastNum, res);
        }
    }
    bool isValidBST(TreeNode* root) {
        cout<<root<<endl;
        if(root==NULL) return true;
        bool res = true;
        long lastNum = LONG_MIN;
        inOrder(root, lastNum, res);
        return res;
    }
};


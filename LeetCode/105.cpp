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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,
                            int i, int j, int p, int q){
        if(j<i)
            return NULL;
      
        TreeNode* root = new TreeNode(preorder[i]);
        //寻找inorder中根节点的位置
        int indexRoot;
        for(int k=p;k<=q;k++){
            if(inorder[k] == preorder[i]){
                indexRoot = k;
                break;
            }
        }
        int lenLeftTree = k - p; 
        int lenRightTree = q - k; 
        //确定左子树区间
        int iLeft = i+1; 
        int jLeft = iLeft + lenLeftTree - 1;
        int pLeft = p;
        int qLeft = pLeft + lenLeftTree - 1;
        root->left = constructTree(preorder, inorder, iLeft, jLeft, pLeft, qLeft)

        
        //确定右子树区间
        int iRight = j - (lenRightTree - 1);
        int jRight = j;
        int pRight = q - (lenRightTree - 1);
        int qRight = q;
        root->right = constructTree(preorder, inorder, iRight, jRight, pRight, qRight)
        
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        int i = 0, j = len - 1, p = 0; q = len - 1;
        return constructTree(preorder, inorder, i, j, p, q);
    }
};

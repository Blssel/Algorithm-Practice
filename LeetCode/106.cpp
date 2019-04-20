class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0) return NULL;
    int root_val = postorder[postorder.size() - 1];
    //cout<<root_val<<endl;
    vector<int> left_inorder;
    vector<int> left_postorder;
    vector<int> right_inorder;
    vector<int> right_postorder;
    int len_of_left = 0;
    while (true) {
      if (inorder[len_of_left] != root_val) {
        //cout<<"###"<<endl;
        left_inorder.push_back(inorder[len_of_left]);
        len_of_left++;
      }
      else {
        break;
      }
    }
    for (int i = 0; i < len_of_left; i++) {
      left_postorder.push_back(postorder[i]);
    }
    for (int i = len_of_left + 1; i < inorder.size(); i++) {
      right_inorder.push_back(inorder[i]);
    }
    for (int i = len_of_left; i < postorder.size() - 1; i++) {
      right_postorder.push_back(postorder[i]);
    }
    TreeNode* root = new TreeNode(root_val);
    root->left = buildTree(left_inorder, left_postorder);
    root->right = buildTree(right_inorder, right_postorder);
    return root;
  }
};

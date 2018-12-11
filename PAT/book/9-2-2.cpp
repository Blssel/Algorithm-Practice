void inorder(node* root){
  if(root==null)
    return;
  inorder(root->left);
  vist(root);
  inorder(root->right);
}



void inorder(node* root){
  if(root == null){
    return;
  }
  if(root->left != null){
    inorder(root->left);
  }
  vist(root);
  inorder(root->right);
}

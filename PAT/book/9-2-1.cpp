void preorder(node* root){
  if(root==null){
    return;
  }
  visit(root);
  preorder(root->left);
  preorder(root->right);
}





void preorder(node* root){
  if(root == null){
    return;
  }
  vist(root);
  if(root->left != null){
    preorder(root->left);
  }
  if(root->right != null){
    preorder(root->right);
  }
}

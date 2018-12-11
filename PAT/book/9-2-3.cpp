void postorder(node* root){
  if(root == null){
    return;
  }
  postorder(root->lchild);
  postorder(root->rchild);
  vist(root);
}


void postorder(node* root){
  if(root == null)
    return;
  if(root->lchild != null){
    postorder(root-lchild);
  }
  if(root-rchild != null){
    postorder(root-rchild);
  }
  vist(root);
}

#include<queue>
using namespace std;

void layerOrder(node* root, queue<node*> q){
  queue<>
  //先访问，再加入队列
  vist(root);
  q.push(root);
  while(!q.empty()){
    node* link = q.fornt()
    q.pop();
    if(link->lchild != null){
      vist(link->lchild);
      q.push(link-lchild);
    }
    if(link->rchild != null){
      vist(link->rchild);
      q.push(link-rchild);
    }
  }
}


void layerOrder(node* root){
  queue<node*> q;
  //先入队，再访问
  q.push(root);
  while(!q.empty()){
    node* link = q.front()
    q.pop();
    vist(link);
    if(link->lchild != null){
      q.push(link->lchild);
    }
    if(link->rchild != null){
      q.push(link->rchild);
    }
  }
}


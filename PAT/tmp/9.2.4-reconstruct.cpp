#include<stdio.h>
using namespace std;

struct Node{
  int data;
  Node lchild;
  Node rchild;
}node;

int N= ;
int preSeq[]={}, inSeq[]={}

node* f(preL, preR, inL, inR){
  if(preL<preR)  
    return null;

  int rootNo = preSeq[preL];//先为当前确定节点建立实例
  node* link = (node*)malloc(sizeof(node));
  link->data = rootNo;

  int rootInd;
  for(int i=inL;i<=inR;i++){
    if(rootNo == inSeq[i])
      rootInd = i;
  }
  lseqLen = rootInd - inL;
  rseqLen = inR - rootInd;

  lchildpreL = preL + 1;
  lchildpreR = preL + lseqLen - 1;
  lchildinL = inL;
  lchildinR = inL + lseqLen - 1; //如果左边为零，则lchildpreL<lchildpreR

  rchildpreL = preR - (rseqLen -1);
  rchildpreR = preR;
  rchildinL = rootInd + 1;//preR-(rseqLen-1)
  rchildinR = inR;

  link->lchild = f(lchildpreL, lchildpreR, lchildinL, lchildinR);
  link->rchild = f(rchildpreL, rchildpreR, rchildinL, rchildinR);
}



int main(){

  return 0;
}

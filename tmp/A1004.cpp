#include<stdio.h>
#include<queue>
using namespace std;

int res[110];

struct node{
  int label;
  int layer;
};

queue<node> q;

int main(){
  int N,M;
  scanf("%d",&N);
  if(N==0)
    return 0;
  else{
    scanf("%d",&M);
    node root;
    root.label=1;
    root.layer=0;
    q.push(root);

    for(int i=0;i<M;i++){
      int id,k;
      scanf("%d%d",&id,&k);
      node n;
      while(1){
        n=q.front();
        q.pop();
        if(n.label != id){
          res[n.layer] += 1;
          continue;
        }
        else
          break;
      }
      for(int j=0;j<k;j++){
        int tmp;
        scanf("%d",&tmp);
        node c;
        c.layer = n.layer + 1;
        c.label = tmp;
        q.push(c);
      }
    }
 
    int numLayers = q.back().layer;
    int leftSize = q.size();
    for(int i=0;i<leftSize;i++){
      node tmp = q.front();
      q.pop();
      res[tmp.layer] += 1;
    }
    
    for(int i=0;i<=numLayers;i++){
      printf("%d",res[i]);
      if(i!=numLayers)
        printf(" ");
    }

    return 0;
  }
}



/*
血的教训：for(int i=0;i<q.size();i++){   q.size()是动态变化的
*/

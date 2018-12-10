#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=10010;
int G[MAXN][MAXN];
int res[MAXN];
bool vis[MAXN];
bool VIS[MAXN];
bool lastVIS[MAXN];


bool changed(int N, bool lastVIS[],bool VIS[]){
  for(int i=1;i<=N;i++){
    if(lastVIS[i]!=VIS[i])
      return true;
  }
  return false;
}

void dfs(int N, int v, int d, int& maxdepth){
  d++;
  vis[v]=true;
  VIS[v]=true;
  for(int j=1;j<=N;j++){
    if(G[v][j]!=0&& vis[j]==false)
      dfs(N,j,d,maxdepth);
  }
  maxdepth=max(maxdepth,d);
}


void travel(int N,int res[],int& numComponents){
  //深度遍历每个节点
  for(int v=1;v<=N;v++){
    for(int i=1;i<=N;i++){
      lastVIS[i]=VIS[i];
    }
    for(int i=1;i<=N;i++)
      vis[i]=false;
    int maxdepth=0;
    int d=0;
    dfs(N, v,d,maxdepth);
    res[v]=maxdepth;
    if(changed(N,lastVIS,VIS))
      numComponents++;
  }
    
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    G[p][q]=1;
    G[q][p]=1;
  }
  int numComponents=0;
  travel(N,res,numComponents);

  if(numComponents>1)
    printf("Error: %d components",numComponents);
  else{
    int maxdepth=1;
    for(int i=1;i<=N;i++){
      if(res[i]>maxdepth){
        maxdepth=res[i];
      }
    }
    for(int i=1;i<=N;i++){
      if(res[i]==maxdepth){
        printf("%d\n",i);
      }
    }
  }
}

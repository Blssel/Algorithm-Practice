#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=10010;
int matrix[MAXN][MAXN];
bool vis[MAXN][MAXN];

void bfs(int i, int j,int N,int M){
  queue<int> q;
  q.push(i);
  q.push(j);
  while(!q.empty()){
    i = q.front();
    q.pop();
    j = q.front();
    q.pop();
    vis[i][j]=true;
    if((i-1)<N && (i-1)>=0 && matrix[i-1][j]==1 && vis[i+1][j]==false){
      q.push(i-1);
      q.push(j);
    }
    if((i+1)<N && (i+1)>=0 && matrix[i+1][j]==1 && vis[i+1][j]==false){
      q.push(i+1);
      q.push(j);
    }
    if((j-1)<M && (j-1)>=0 && matrix[i][j-1]==1 && vis[i][j-1]==false){
      q.push(i);
      q.push(j-1);
    }
    if((j+1)<M && (j+1)>=0 && matrix[i][j+1]==1 && vis[i][j+1]==false){
      q.push(i);
      q.push(j+1);
    }
  }
}

int main(){
  int N=6,M=7;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&matrix[i][j]);
    }
  }
  int numBlock = 0; 
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(matrix[i][j]==1 && vis[i][j]==false){
        numBlock++;
        bfs(i,j,N,M);
      }
    }
  }
  printf("%d\n",numBlock);
}


/*
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0

0 1 1 1 0 0 1
0 0 1 1 0 0 0
0 1 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 1
*/

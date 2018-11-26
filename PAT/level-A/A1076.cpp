#include<stdio.h>
#include<queue>
using namespace std;

const int MAXV = 1010;
const int INF = 1000000000;
int G[MAXV][MAXV] = {0};

void BFS(int u, int n, int l){
  bool inq[MAXV]={false};
  int depth[MAXV]={-1};
  queue<int> q;
  int numForward = 0;
  //numForward += 1;  //访问节点u并入队
  inq[u] = true;
  q.push(u);
  depth[u] = 0;
  
  while(!q.empty()){


    int v = q.front();
    q.pop();
    if(depth[v] == l){
      break;
    }
    for(int i=1;i<=n;i++){
      if(G[v][i]!=0 && inq[i]==false){
        numForward += 1;
        inq[i] = true;
        q.push(i);
        depth[i] = depth[v] + 1;
      }
    }
    //for(int i=1;i<=n;i++){
    //  printf("%d ",depth[i]);
    //}
    //printf("\n");
  }
  printf("%d\n",numForward);
}

int main(){
  int N,L;
  scanf("%d%d", &N, &L);
  int m, user;
  for(int i=1;i<=N;i++){
    scanf("%d", &m);
    for(int j=0;j<m;j++){
      scanf("%d",&user);
      G[user][i] = 1;
    }
  }
  int k;
  scanf("%d",&k);
  int users[k];
  for(int i=0;i<k;i++){
    scanf("%d",&users[i]);
  }
  for(int i=0;i<k;i++){
    BFS(users[i], N, L);
  }

  
  //for(int i=1;i<=7;i++){
  //  for(int j=1;j<=7;j++){
  //    printf("%d ",G[i][j]);
  //    if(j==7)
  //      printf("\n");
  //  }
  //}
}

  




















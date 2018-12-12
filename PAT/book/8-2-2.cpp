#include<stdio.h>
#include<queue>
using namespace std;
/*从起点出发，使用bfs可以找到所有1步可达的点，对这些点来说，1已经是最短距离了；
  然后从这些点出发，用bfs寻找没搜索过的点，便可找到所有距离为2的点，同样，2也是最短距离了；
  。。。综上，用bfs每一步搜索到的点的“层数”都是最短距离*/
struct Node{
  char data;
  int layer;
}node;

const int MAXN=10010;
const int MAXM=10010;

Node matrix[MAXN][MAXM];
bool vis[MAXN][MAXM];

int bfs(int N, int M, int starti, int startj, int endi, int endj){
  queue<int> q;
  q.push(starti);
  q.push(startj);
  matrix[starti][startj].layer = 0;
  while(!q.empty()){
    int i = q.front();
    q.pop();
    int j = q.front();
    q.pop();
    vis[i][j] = true;
    if(vis[endi][endj]==true)
      return matrix[endi][endj].layer; 
    if((i-1)>=0 && matrix[i-1][j].data!='*' && vis[i-1][j]==false){
      q.push(i-1);
      q.push(j);
      matrix[i-1][j].layer = matrix[i][j].layer + 1;
    }
    if((i+1)<N && matrix[i+1][j].data!='*' && vis[i+1][j]==false){
      q.push(i+1);
      q.push(j);
      matrix[i+1][j].layer = matrix[i][j].layer + 1;
    }
    if((j-1)>=0 && matrix[i][j-1].data!='*' && vis[i][j-1]==false){
      q.push(i);
      q.push(j-1);
      matrix[i][j-1].layer = matrix[i][j].layer + 1;
    }
    if((j+1)<M && matrix[i][j+1].data!='*' && vis[i][j+1]==false){
      q.push(i);
      q.push(j+1);
      matrix[i][j+1].layer = matrix[i][j].layer + 1;
    }
  }
}

int main(){
  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++){
    getchar(); //前一个换行，会被这里吸收
    for(int j=0;j<M;j++){
      scanf("%c",&matrix[i][j].data);
    }
  }
  int starti,startj,endi,endj;
  scanf("%d%d%d%d",&starti,&startj,&endi,&endj);
  int res = bfs(N, M, starti,startj,endi,endj);
  printf("%d\n",res);
}

// 一旦某个点被确定为最短，后来再开放路径也不可能比他更短，也不可能一样长。
#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXV=510;
const int INF=1000000000;
int numPeople[MAXV], G[MAXV][MAXV];

int main(){
  // input
  int N, M, C1, C2;
  scanf("%d%d%d%d",&N,&M,&C1,&C2);
  for(int i=0;i<N;i++){
    scanf("%d",&numPeople[i]);
  }
  int c1,c2,L;
  for(int i=0;i<M;i++){
    scanf("%d%d%d",&c1,&c2,&L);
    G[c1][c2] = L;
    G[c2][c1] = L;
  }
  // solution
  bool vis[MAXV] = {false};
  int knownShotest[MAXV];
  fill(knownShotest,knownShotest+MAXV,INF);
  knownShotest[C1] = 0;
  int numRoads[MAXV]={0};
  numRoads[C1] = 1;
  int numHands[MAXV]={0};
  numHands[C1] = numPeople[C1];


  for(int i=0;i<N;i++){
    int MIN=INF,minInd; 
    for(int j=0;j<N;j++){
      if(vis[j]==false && knownShotest[j]<MIN){
        MIN=knownShotest[j];
        minInd=j;
      }
    }
    //printf("%d %d\n",MIN,minInd);
    if(MIN == INF)
      break;
    vis[minInd]=true;
    for(int j=0; j<N; j++){ //update
      if(vis[j]==false && G[minInd][j]!=0 && knownShotest[minInd]+G[minInd][j]<knownShotest[j]){
        knownShotest[j]=knownShotest[minInd]+G[minInd][j];
        //printf("###%d %d %d\n",j,knownShotest[j],numRoads[minInd]);
        numRoads[j]=numRoads[minInd];
        numHands[j]=numPeople[j]+numHands[minInd];
      }
      else if(vis[j]==false && G[minInd][j]!=0 && knownShotest[minInd]+G[minInd][j]==knownShotest[j]){
        //printf("#######%d ########",j);
        numRoads[j] = numRoads[j]+numRoads[minInd]; 
        if(numPeople[j]+numHands[minInd]>numHands[j]){
          numHands[j]=numPeople[j]+numHands[minInd]; 
        }
      }

    }
  }
  printf("%d %d",numRoads[C2], numHands[C2]);
}


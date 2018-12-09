#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=1001;
const int MAXV=10001;
int opt[MAXN][MAXV], w[MAXN], c[MAXV];

int main(){
  int N,V;
  scanf("%d %d",&N,&V);
  for(int i=1;i<=N;i++){
    scanf("%d",&w[i]);
  }
  for(int i=1;i<=N;i++){
    scanf("%d",&c[i]);
  }
  
  for(int i=0;i<=N;i++){
    for(int j=0;j<=V;j++){
      opt[i][i]=0;
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=V;j>=w[i];j--){
      opt[i][j]=max(opt[i-1][j-w[i]]+c[i], opt[i-1][j]);
    }
  }

  //int res=0;
  //for(int i=1;i<=N;i++){
  //  for(int j=1;j<=V;j++){
  //    if()opt[i][]
  //  }
  //}
  printf("%d",opt[N][V]);
  return 0;  
}

#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=30;
int weight[MAXN], value[MAXN];

int opt(int i, int v){
  if(i==1){
    if(v>=weight[i])
      return value[i];
    else
      return 0;
  }
  
  if(weight[i]>v)     //第i个太大，装不下，所以一定不装，就不用考虑装的情况。考虑了反而会导致v-weight[i]称为负数，且增加计算量
    return opt(i-1,v);
  else
    return max(opt(i-1,v-weight[i])+value[i],
               opt(i-1,v));
}


int main(){
  int N, V;
  scanf("%d%d",&N,&V);
  for(int i=1;i<=N;i++){
    scanf("%d",&weight[i]);
  }
  for(int i=1;i<=N;i++){
    scanf("%d",&value[i]);
  }

  int res = opt(N,V);
  printf("%d\n",res);
}

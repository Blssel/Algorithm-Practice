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
  
  if(weight[i]>v)
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

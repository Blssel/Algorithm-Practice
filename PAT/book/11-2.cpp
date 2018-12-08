#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=10010;
int A[MAXN], dp[MAXN];

int maxContSum(int n, int dp[]){
  if(n==0){
    int tmp=A[n];
    dp[n]=tmp;
    return tmp;
  }
  int tmp = max(A[n],A[n]+maxContSum(n-1,dp));
  dp[n]=tmp;
  return tmp;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  /*
  //递推写法
  dp[0]=A[0];
  for(int i=1;i<n;i++){
    if(dp[i-1]+A[i]>A[i]){
      dp[i] = dp[i-1]+A[i];
    }else{
      dp[i] = A[i];
    }
    //dp[i] = max(dp[i-1]+A[i], A[i]); #include<algorithm>
  }
  */

  //递归写法
  int tmp =maxContSum(n-1,dp);

  int res=dp[0];
  for(int i=0;i<n;i++){
    if(dp[i]>res){
      res=dp[i];
    }
  }
  printf("%d",res);
      


  return 0;
}

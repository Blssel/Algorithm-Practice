#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAXN=10001;
int A[MAXN], dp[MAXN];

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  dp[0]=1;
  for(int i=1;i<n;i++){
    dp[i]=1;
    for(int j=i-1;j>=0;j--){
      if(A[i]>=A[j]&&dp[i]<=dp[j]){
        dp[i]=dp[j]+1;
      }
    }
  }
  int res=dp[0];
  for(int i=0;i<n;i++){
    if(dp[i]>res){
      res=dp[i];
    }
  }
  printf("%d",res);

  return 0;
}

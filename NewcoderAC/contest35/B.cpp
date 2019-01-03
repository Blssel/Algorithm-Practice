#include<stdio.h>
#include<math.h>
using namespace std;
 
const long long m = 1000000007;
 
int main(){
  int T, N, A, B;
  long long mod = pow(10,9) + 7;
  scanf("%d",&T);
  for(int i=0;i<T;i++){
    scanf("%d%d%d",&N, &A, &B);
    
    long long dpYuan[N][A];
    long long dpFu[N][B];
    for(int i=0;i<N;i++){
      for(int j=0;j<A;j++)
        dpYuan[i][j] = 0;
      for(int k=0;k<B;k++)
        dpFu[i][k] = 0;
    }

    dpYuan[0][0]=5;
    dpFu[0][0]=21;
    for(int i=1;i<N;i++){
      long long sumEndWithFu = 0;
      for(int j=0;j<B;j++)
        sumEndWithFu = (sumEndWithFu +  dpFu[i-1][j]) % mod;
      dpYuan[i][0] = (sumEndWithFu*5) % mod;
      for(int k=1;k<A;k++)
        dpYuan[i][k] = (dpYuan[i-1][k-1]*5) % mod;
      
      long long sumEndWithYuan = 0;
      for(int m=0;m<A;m++)
        sumEndWithYuan = (sumEndWithYuan + dpYuan[i-1][m])%mod;
      dpFu[i][0] = (sumEndWithYuan*21)%mod;
      for(int n=1;n<B;n++)
        dpFu[i][n] = (dpFu[i-1][n-1]*21)%mod;
    }



    long long res=0;
    for(int k=0;k<N;k++){
      for(int i=0;i<A;i++)
        //printf("%lld ",dpYuan[k][i]);
        res = (res + dpYuan[k][i])%m;
      for(int j=0;j<B;j++)
        //printf("%lld ",dpFu[k][j]);
        res = (res + dpFu[k][j])%m;
    }
    
    printf("%lld\n",res);
  }
  return 0;
}

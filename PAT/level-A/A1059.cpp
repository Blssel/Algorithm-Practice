#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
map<int,int> primeFactors;
bool isPrime(int n){
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0)
      return false;
  }
  return true;
}

/*
暴力解：
缺点：如果n的质因数如下特点二，则会多遍历了根号n ~ 最后一个质因数之间的情况
*/
/*
int main(){
  int N=97532468;
  // 以素数为主
  for(int i=2;i<=N;i++){
    if(isPrime(i) && N%i==0){
      printf("%d ",i);
      N /= i;
      while(N%i==0){
        printf("%d ",i);
        N /= i;
      }
    }
    if(N==1)
      break;
  }
  
  // 以n为主
  int ii=2;
  while(N!=1){
    
    if(isPrime(ii) && N%ii==0){
      
      N /= ii;
      while(N%ii==0)
        N /= ii;
    }else{
      ii++;
    }
  }
  return 0;
}
*/



/*
1. 短除法就能胜任，并且质因子分解是唯一的！
2.特点一：用短除法，质因子会从小到大，依次出现，并且同一个质因子会重复出现多次
3.特点二：质因子要不都小于等于根号n，要么只有一个大于根号n，其余都小于根号n。 所以1-根号n这些质因数至少需要过一遍，如果剩余的数！=1，说明最后一个一定是质数（稍微反证就能证明）
*/

void storePrime(int n, map<int ,int>& factors){
  if(factors.find(n) != factors.end()){
    factors[n] += 1;
  }else{
    factors[n] = 1;
  }

}

int main(){
  long long N;
  scanf("%lld", &N);
  printf("%lld=",N);
  if(N==1)
    printf("1");
  else{
    for(int i=2;i<=sqrt(N);i++){
      if(isPrime(i) && N%i==0){
        storePrime(i, primeFactors);
        N /= i;

        while(N%i==0){
          storePrime(i, primeFactors);
          N /= i;
        }

        if(N==1)
          break;
      }
    }
    if(N!=1)
      storePrime(N,primeFactors);
    
    int numPrimes = primeFactors.size();
    for(map<int,int>::iterator it=primeFactors.begin(); it!=primeFactors.end();it++){
      int exponent = it->second;
      printf("%d",it->first);
      if(exponent>=2)
        printf("^%d",exponent);
      numPrimes--;
      if(numPrimes!=0)
        printf("*");
    }
  }

  return 0;
}





















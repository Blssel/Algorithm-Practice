#include<stdio.h>
using namespace std;
 
bool isHalfBin(long long n){
    if(n%2==1 || n<4)
        return false;
    else{
        int numOne=0;
        while(n!=0){
          int remainder = n%2;
          n /= 2;
          if(remainder==1)
            numOne++;
        }
        if(numOne==1 || numOne==2)
          return true;
        else
          return false;
    }
}
 
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long N;
        scanf("%lld",&N);
         
        bool res = isHalfBin(N);
        if(res==true)
            printf("YES");
        else
            printf("NO");
        if(i!=T-1)
            printf("\n");
    }
    return 0;
}


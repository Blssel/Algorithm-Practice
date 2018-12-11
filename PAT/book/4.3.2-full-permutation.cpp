#include<stdio.h>
using namespace std;

const int MAXN=10010;
void fullPerm(int N, int ind, int perm[], bool used[]){
  ind++;
  if(ind==N){
    return;
  }
  for(int i=0;i<N;i++){ 
    if(used[i] == false){
      perm[ind] = i;
      used[i] = true;
      if(ind == N-1){
        //output
        for(int j=0;j<N;j++){
          printf("%d ",1+perm[j]);
        }
        printf("\n");
      }
      fullPerm(N,ind,perm,used);
      used[i] = false;
    }
  }
}

int main(){
  int N=4; //表示对0~N-1做full permutation
  int perm[N];
  bool used[N];
  int ind = -1;

  fullPerm(N,ind,perm,used);

  return 0;
}

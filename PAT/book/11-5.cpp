#include<stdio.h>
#include<cstring>
using namespace std;

const int MAXN=1001;
char str[MAXN];
int isHui[MAXN][MAXN];
int main(){
  scanf("%s",str);
  int stringlen=strlen(str);
  int res=1;
  for(int l=0;l<stringlen;l++){
    for(int i=0;i<=stringlen-l;i++){
      int j=i+l;
      if(i==j){
        isHui[i][j] = 1; //是回文
      }else if(i==j-1){
        isHui[i][j] = (str[i]==str[j])?1:0;
        res=2;
      }else if(isHui[i+1][j-1]==1&&str[i]==str[j]){
        isHui[i][j]=1;
        if(j-i+1>res)
          res=j-i+1;
      }else{
        isHui[i][j]=0;
      }
    }
  }
  printf("%d",res);
}

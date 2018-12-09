#include<stdio.h>
using namespace std;
const int MAXN=100010;
typedef struct Node{
  char c;
  int next;
}node;

node words[MAXN];
int word1Addr[MAXN], word2Addr[MAXN];


int main(){
  int addr1,addr2,N;
  scanf("%d%d%d",&addr1,&addr2,&N);
  int addr, nextAddr;
  char c;
  for(int i=0;i<N;i++){
    scanf("%d %c %d",&addr, &c, &nextAddr);
    words[addr].c = c;
    words[addr].next = nextAddr;
  }

  int l1=addr1, lenWord1=0;
  while(l1!=-1){
    word1Addr[lenWord1++]=l1;
    l1=words[l1].next;
  }
  int l2=addr2, lenWord2=0;
  while(l2!=-1){
    word2Addr[lenWord2++]=l2;
    l2=words[l2].next;
  }

  int res=-1;
  while(word1Addr[lenWord1-1]==word2Addr[lenWord2-1]&&lenWord1>0&&lenWord2>0){
    res=word1Addr[lenWord1-1];
    lenWord1--;
    lenWord2--;
  }
  if(res==-1)
    printf("%d",res);
  else
    printf("%05d",res);
  

  return 0;
}

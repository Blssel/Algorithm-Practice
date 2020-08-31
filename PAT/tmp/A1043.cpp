#include<stdio.h>
#include<vector>
using namespace std;
struct Node{
  char data;
  int layer;
}node;

const int MAXN=10010;
const int MAXM=10010;

Node matrix[MAXN][MAXM];
vector<int> postordered;

int arr[MAXN];
void isBSTpostOrder(int start, int end, bool& isbst){
  if(start == end){
    postordered.push_back(arr[start]);
    return;
  }
  int boundary;
  boundary = start + 1;
  if(arr[start+1]<arr[start]){
    for(int i=start+1;i<=end;i++){
      if(arr[i]<arr[start])
        boundary = i;
      else
        break;
    }

    isBSTpostOrder(start+1,boundary, isbst);
    if(boundary!=end){
      for(int i=boundary+1;i<=end;i++){
        if(arr[i]<arr[start]){  //如果大于等于，则什么也不做，否则就说明有错
          isbst = false;
          return;
        }  
      }
      isBSTpostOrder(boundary+1,end, isbst);
    }
  }
  if(arr[start+1]>=arr[start]){
    for(int i=start+1;i<=end;i++){
      if(arr[i]>=arr[start])
        boundary = i;
      else
        break;
    }
    isBSTpostOrder(start+1,boundary, isbst);
    if(boundary != end){
      for(int i=boundary+1;i<=end;i++){
        if(arr[i]>=arr[start]){  //如果小于，则什么也不做，否则就说明有错
          isbst = false;
          return;
        }  
      }
      isBSTpostOrder(boundary+1,end, isbst);
    }
  }
  postordered.push_back(arr[start]);
}


int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  bool isbst = true;
  int start=0, begin=N-1;
  //判断是否是BST or mirror image BST
  isBSTpostOrder(start, begin, isbst);
  if(isbst){
    printf("YES\n");
    for(int i=0;i<postordered.size();i++){
      printf("%d",postordered[i]);
      if(i!=postordered.size()-1)
        printf(" ");
    }
  }
  else
    printf("NO");
  
}


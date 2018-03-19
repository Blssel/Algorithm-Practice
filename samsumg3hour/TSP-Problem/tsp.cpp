#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX

int N;
//int node[24]; //包括起点终点，最多24个
int coordinate[24]; //
int dist[12][12]; //索引0代表起点，1代表终点 值为-1代表不通
int curTrace[12]; //索引代表第几步，对应内容代表选的第几号节点（第0个位置不用，第一步默认走第0个节点，所以存0）
int bestTrace[12];
int curDist=0;
int bestDist=INF;
int isTravelled[12]; //默认为0，表示未访问过，1表示访问过
void calDist(int n,int *coord,int dis[12][12]){
/*利用coor坐标计算两两之间距离 计算公式用 |x1-x2| + |y1-y2|*/
  for (int i=0;i<n+2;i++){
    for(int j=0;j<n+2;j++){
      dist[i][j]=abs(coordinate[2*i] - coordinate[2*j]) +abs(coordinate[2*i+1] - coordinate[2*j+1]);
    }
  }
}

void input_data(){
  //读入元素个数，以及所有坐标
  scanf("%d",&N);
  int i=2*(N+2);
  int index=0;
  while(i-->0){
    scanf("%d",&coordinate[index++]);
  }
  // 把终点坐标移动到最后
  int x=coordinate[2];
  int y=coordinate[3];
  for(int k=4;k<2*(N+2);k++){
    coordinate[k-2]=coordinate[k];
  }
  coordinate[2*(N+2)-2]=x;
  coordinate[2*(N+2)-1]=y;
}

void backTrace(int n){
  //如果到了最后一步，即下一步就是终点，则比较后丢弃或更新当前最优
  if(n>N){
    if(curDist+dist[curTrace[n-1]][N+1]<bestDist){
      //更新
      bestDist=curDist+dist[curTrace[n-1]][N+1];
      for(int i=0;i<N+2;i++){
        bestTrace[i]=curTrace[i];
      }
    }
    
  }
  //对每一步，需要从未访问的节点选取一个作为下一步的访问点
  for(int j=1;j<=N;j++){
    if(isTravelled[j]==0&& curDist+dist[curTrace[n-1]][j]<bestDist){
      curTrace[n]=j;
      isTravelled[j]=1;
      curDist+=dist[curTrace[n-1]][j];
      backTrace(n+1);
      // 一种可以走的情况试完，应该清空记录 平等的对待另一种可能性
      curDist-=dist[curTrace[n-1]][j];
      isTravelled[j]=0;
    }
  } 
}
int main(){
  //从命令行读入数据，并计算距离矩阵
  input_data();
  calDist(N, coordinate, dist);
  //for(int i=0;i<2+N;i++){
  //  for(int j=0;j<2+N;j++){
  //    printf("%d ",dist[i][j]);
  //  }
  //  printf("\n");
  //}
  
  //
  curTrace[0]=0;
  isTravelled[0]=1;
  backTrace(1); 
  printf("The answer is: %d\n",bestDist);










}

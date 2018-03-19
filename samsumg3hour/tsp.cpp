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
int cur_dist=0;
int best_dist=INF;

void calDist(int n,int *coord,int dis[12][12]){
/*利用coor坐标计算两两之间距离 计算公式用 |x1-x2| + |y1-y2|*/
  for (int i=0;i<n+2;i++){
    for(int j=i;j<n+2;j++){
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
}

int main(){
  //从命令行读入数据，并计算距离矩阵
  input_data();
  calDist(N, coordinate, dist);
//  for(int i=0;i<2+N;i++){
//    for(int j=0;j<2+N;j++){
//      printf("%d ",dist[i][j]);
//    }
//    printf("\n");
//  }
  

}

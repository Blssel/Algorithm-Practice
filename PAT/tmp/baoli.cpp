#include<stdio.h>
#include<algorithm>
using namespace std;
//表示尝试第i个的两种情况，累加至变量中，若重量未超，则继续尝试第i+1个，
int res, weightsAccumulated=0, valuesAccumulated=0;
int W;
int weight[MAXN],value[MAXN];

void f(int i, int& weightsAccumulated,int& valuesAccumulated){
  if(i=N){
    res = max(res,valuesAccumulated);
    return;
  }

  int tmpWeight = weightsAccumulated;
  int tmpValue = valuesAccumulated;
  
  //选
  weightsAccumulated += w[i];
  valuesAccumulated += v[i];
  if(weightsAccumulated>W){
    res = max(res,valuesAccumulated-v[i]);
    return;
  }
  f(i+1, weightsAccumulated, valuesAccumulated);

}


int main(){


}




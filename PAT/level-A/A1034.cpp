#include<stdio.h>
#include<map>
#include<vector>
#include <string>
using namespace std;
const int MAXV = 2000;
int G[MAXV][MAXV] = {0};
int numV = 0;

void DFS(int u, bool vis[], map<int,int> &weights){
  vis[u]=true;
  weights[u] = 0;
  for(int i=0; i<numV; i++){
    if(G[u][i] != 0){
      weights[u] += G[u][i];
    }
  }
  for(int i=0; i<numV;i++){
    if(G[u][i]!=0 && vis[i]==false){
      DFS(i, vis, weights);
    }
  }
}

void DFSTrave(vector<map<int,int> > &result){
  bool vis[numV]={false};
  for(int u=0;u<numV;u++){
    if(vis[u]==false){
      map<int ,int> weights; //该团体每人的权重
      DFS(u, vis, weights);
      //收集结果
      result.push_back(weights);
    }
  }
}

void _map(string name, int &numV, map<string,int> &name2index, map<int,string> &index2name){
  map<string, int>::iterator it = name2index.find(name);
  if(it == name2index.end()){  //如果不存在该映射，则添加进去
    name2index[name] = numV;
    index2name[numV++] = name;
  }
}

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  
  map<string,int> name2index;
  map<int,string> index2name;
  // construct adjacent martix
  string name1, name2;
  name1.resize(10);
  name2.resize(10);
  int weight;
  for(int i = 0; i < n; i++){
    scanf("%s %s %d", &name1[0],&name2[0],&weight);
    _map(name1, numV, name2index, index2name); //添加映射
    _map(name2, numV, name2index, index2name);
    G[name2index[name1]][name2index[name2]] += weight;  //构建邻接矩阵
    G[name2index[name2]][name2index[name1]] += weight;
  }
  
  vector<map<int,int> > result;
  DFSTrave(result);
  
  int numGangs=0;
  map<string,int> head_numMem;
  for(int i=0; i<result.size(); i++){
    int numTimes = 0, maxx=0, head;
    for(map<int ,int>::iterator it=result[i].begin(); it!=result[i].end(); it++){
      numTimes += it->second;
      if(it->second > maxx){
        maxx = it->second;
        head = it->first;
      }
    }
    numTimes = numTimes/2;
    if (numTimes > k && result[i].size()>2){
      numGangs += 1;
      head_numMem[index2name[head]] = result[i].size();
    }
  }
  
  printf("%d\n",numGangs);
  for(map<string,int>::iterator it=head_numMem.begin(); it!=head_numMem.end(); it++){
    printf("%s %d\n",(it->first).c_str(), it->second);
  }
}





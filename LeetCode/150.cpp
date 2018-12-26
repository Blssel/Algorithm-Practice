#include<stdio.h>
#include<vector>
#include<stack>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution{
  public:
    int evalRPN(vector<string>& tokens){
      stack<int> s;
      for(vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++){
        if(*it!="+" && *it!="-" && *it!="*" && *it!="/"){
          s.push(atoi((*it).c_str()));
        }else{
          int a = s.top();  //添加stdlib.h
          s.pop();
          int b = s.top();
          s.pop();
          if(*it == "+") s.push(b+a);
          if(*it == "-") s.push(b-a);
          if(*it == "*") s.push(b*a);
          if(*it == "/") s.push(b/a);
        }
      }
      return s.top();
    }
};

int main(){
  vector<string> tokens;
  int N;
  scanf("%d",&N);
  char tmp[10];
  for(int i=0;i<N;i++){
    scanf("%s",tmp);
    tokens.push_back(tmp);
  }
  
  Solution slt;
  int res = slt.evalRPN(tokens);
  printf("%d\n",res);
  return 0;
}



/*
这题重点还是要把题意捋顺：
1. 从前往后找到“第一个”运算符a，该操作符前一定存在两个数（不是表达式）。反证法：如果存在表达式，那么该表达式中也存在运算符b，那么a就不是第一个运算符了。  这个子表达式就是最高的运算优先级，把它算了，变成数替换原表达式。   
2. 用栈可以节省复杂度，不用栈则每次都要从头往后找运算符。  需要熟练！！
3.by the way, 原式的最后三个元素一定不可能是这种类型：数，数，操作符

4. 注意出栈次序（决定了运算次序）
*/

/*
http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3341&konwledgeId=158
*/


#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long get_num_nodes(long prefix, long n) {
  long res = 1;
  long base = 10;
  while (true) {
    if (prefix * base + base - 1 <= n) {
      res = res + base;
      base = base * 10;
    }
    else if (prefix * base <= n) {
      res = res + (n - prefix * base + 1);
      break;
    }
    else {
      break;
    }
  }
  return res;
}
int main() {
  long n, m;
  while (cin >> n >> m) {
    long result = 1;
    while (m != 0) {
      long num_nodes = get_num_nodes(result, n);
      if (num_nodes >= m) {
        if (m != 1)
          result = result * 10;
        m = m - 1;
      }
      else {
        result = result + 1;
        m = m - num_nodes;
      }
    }
    cout << result << endl;
  }
  return 0;
}

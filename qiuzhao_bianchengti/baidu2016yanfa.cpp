/*https://www.nowcoder.com/profile/8440780/test/24442047/25948*/
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <iomanip>

using namespace std;

namespace baidu2016yanfa {
int first() {
  int n, t, c;
  while (cin >> n >> t >> c) {
    vector<int> crimes(n);
    for (int i = 0; i < n; i++) {
      cin >> crimes[i];
    }
    int res = 0;
    int s = 0;
    for (int begin = 0; begin + c - 1 < n; begin++) {
      if (begin == 0) {
        for (int i = 0; i <= begin + c - 1; i++) {
          s += crimes[i];
        }
      }
      else {
        s = s - crimes[begin - 1] + crimes[begin + c - 1];
      }
      if (s <= t) {
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}


int second() {
  int n;
  int x, y;
  while (cin >> n) {
    int res;
    int x_min = 100000000;
    int x_max = -100000000;
    int y_min = 100000000;
    int y_max = -100000000;
    for (int i = 0; i < n; i++) {
      cin >> x;
      cin >> y;
      if (x < x_min) {
        x_min = x;
      }
      if (x > x_max) {
        x_max = x;
      }
      if (y < y_min) {
        y_min = y;
      }
      if (y > y_max) {
        y_max = y;
      }
    }
    res = pow(max(x_max - x_min, y_max - y_min),2);
    cout << res << endl;
  }
  return 0;
}



int third() {
  int n, m, x, y, t;
  while (cin >> n >> m >> x >> y >> t) {
    vector<vector<double>> p(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> p[i][j];
      }
    }
    double p1 = 1.0 - pow(1.0 - p[x-1][y - 1], t);
    double p_reverse = 0.0;
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < m; v++) {
        p_reverse += (1.0 - p[u][v]);
      }
    }
    p_reverse *= 1.0 / (n*m);
    double p2 = 1.0 - pow(p_reverse, t);
    if (p1 > p2) {
      cout << "cc" << endl;
      printf("%.2f\n", p1);
      //cout << setprecision(2) << p1 << endl;
    }
    else if(p1 == p2){
      cout << "equal" << endl;
      printf("%.2f\n", p2);
      //cout << setprecision(2) << p1 << endl;
    }
    else {
      cout << "ss" << endl;
      printf("%.2f\n", p2);
      //cout << setprecision(2) << p2 << endl;
    }
  }
  return 0;
}

int n, m, k;
double prob(int x, int y, vector<vector<double>>& dp, vector<vector<int>>& arr) {
  if (dp[x][y] >= 0.0) {
    return dp[x][y];
  }
  if (arr[x][y] == 1) {
    dp[x][y] = 0;
  }
  else {
    double p_left, p_up;
    if (y - 1 < 0) { //左边不存在
      p_left = 0;
    }
    else if(x+1<n){ //左边存在，且可向下走（一定可以向右）
      p_left = 1.0 / 2.0*prob(x, y - 1, dp, arr);
    }
    else {  //左边存在，且不可向下走（一定可以向右）
      p_left = prob(x, y - 1, dp, arr);
    }

    if (x - 1 < 0) { //上边不存在
      p_up = 0;
    }
    else if (y + 1<m) { //上边存在，且可向右走（一定可以向下）
      p_up = 1.0 / 2.0*prob(x - 1, y, dp, arr);
    }
    else {  //上边存在，且不可向右走（一定可以向下）
      p_up = prob(x - 1, y, dp, arr);
    }
    dp[x][y] = p_left + p_up;
  }
  return dp[x][y];
}

int forth() {
  while (cin >> n >> m >> k) {
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int x, y;
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      arr[x - 1][y - 1] = 1;
    }
    vector<vector<double>> dp(n, vector<double>(m, -1.0));
    dp[0][0] = 1;
    double res = prob(n - 1, m - 1, dp, arr);
    //cout << setprecision(2) << res;
    printf("%.2f\n", res);
  }
  return 0;
}


}


int main() {
  //baidu2016sihxi::first();
  //baidu2016sihxi::second();
  //baidu2016sihxi::third();
  baidu2016sihxi::forth();
  return 0;
}


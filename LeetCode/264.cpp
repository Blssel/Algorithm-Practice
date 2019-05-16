// 能撑到1000以上，1690超时
class Solution {
public:
  int nthUglyNumber(int n) {
    long long MAX_L = 1000000000;
    vector<bool> dp(MAX_L, false);

    dp[1] = true;
    dp[2] = true;
    dp[3] = true;
    dp[4] = true;
    dp[5] = true;
    if (n <= 5) return n;
    int p = 2;
    int num = 2;
    while (num < n) {
      if (p >= 1000000)
        cout << p << endl;

      if (p * 2 <= MAX_L && dp[p * 2] == false) {
        dp[p * 2] = true;
      }
      if (p * 3 <= MAX_L && dp[p * 3] == false) {
        dp[p * 3] = true;
      }
      if (p * 5 <= MAX_L && dp[p * 5] == false) {
        dp[p * 5] = true;
      }
      num++;
      p++;
      while (dp[p] == false) {
        p++;
        //cout << "aaaaaaaaaaa" << endl;
      }

    }
    return p;
  }
};

class Solution {
public:
  long long helper(string s, int lenStr, long long dp[]) {
    if (lenStr == 1) {
      if (atoi(s.substr(0, 1).c_str()) > 0)
        return 1;
      else
        return 0;
    }
    if (lenStr == 0) return 1;
    if (dp[lenStr] != -1) return dp[lenStr];
    int s1 = atoi(s.substr(0, 1).c_str());
    int s2 = atoi(s.substr(0, 2).c_str());

    if (!((s1 > 0 && s1 <= 26) || (s2 > 9 && s2 <= 26))) {
      dp[lenStr] = 0;
      return 0;
    }
    
    long long num1 = helper(s.substr(1, s.length() - 1), s.length() - 1, dp);
    long long num2 = helper(s.substr(2, s.length() - 2), s.length() - 2, dp);
    int res = 0;
    if (s1 > 0 && s1 <= 26) {
      res += num1;
    }
    if (s2 >9 &&s2 <= 26) {
      res += num2;
    }
    
    dp[lenStr] = res;
    return res;
  }
  int numDecodings(string s) {
    long long dp[10000];
    for (int i = 0; i < 10000; i++) {
      dp[i] = -1;
    }

    return helper(s, s.length(), dp);
  }
};


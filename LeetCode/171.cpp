class Solution {
public:
  int titleToNumber(string s) {
    int len = s.length();
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
      res += pow(26, len-1-i)*(s[i] - 'A' + 1);
    }
    return res;
  }
};

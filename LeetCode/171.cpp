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


class Solution {
public:
  int titleToNumber(string s) {
    int len = s.length();
    if (len == 0) return 0;
    int res = s[len-1] - 'A' + 1;
    int base = 1;
    for (int i = len - 2; i >= 0; i--) {
            base = base*26;
      res += (s[i] - 'A' + 1) *base;
    }
    return res;
  }
};

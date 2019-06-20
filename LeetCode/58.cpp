class Solution {
public:
  int lengthOfLastWord(string s) {
    int p = s.length() - 1;
    while (p >= 0) {
      if (s[p] == ' ') {
        p--;
      }
      else {
        break;
      }
    }
    int res = 0;
    while (p >= 0) {
      if (s[p] == ' ') {
        break;
      }
      else {
        p--;
        res++;
      }
    }
        return res;
  }
};

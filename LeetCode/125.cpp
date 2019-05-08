class Solution {
public:
  bool isPalindrome(string s) {
    int p = 0;
    while (p < s.length()) {
      if (s[p] >= 'A' && s[p] <= 'Z') {
        s[p] = s[p] + 32;
      }
      if (!((s[p] >= 'a' && s[p] <= 'z') || (s[p] >= '0' && s[p] <= '9'))) {
        s.erase(s.begin() + p);
      }
      else {
        p++;
      }
    }
    int l = ceil(s.length() / 2.0) - 1;
    int r = s.length() / 2;
    cout << l << endl;
    cout << r << endl;
    cout << s << endl;
        //if(s.length()==1) return false;
    while (l >= 0) {
      if (s[l] != s[r]) {
        return false;
      }
      else {
        l--;
        r++;
      }
    }
    return true;
  }
};

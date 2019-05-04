class Solution {
public:
  int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
    int i = 0;
    while (i < haystack.length()) {
      if (haystack[i] == needle[0]) {
        if (haystack.substr(i, needle.length()) == needle)
          return i;
        else {
          i++;
          continue;
        }
      }
      else {
        i++;
      }
    }
    return -1;
  }
};

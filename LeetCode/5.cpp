class Solution {
public:
    string longestPalindrome(string s) {
        //端点ij的遍历顺序应该按照间隔由小到大
        int strLen = s.size();
        if(strLen == 0){
            return "";
        }
        int dp[strLen][strLen];
        for(int i=0; i<strLen; i++){
            for(int j=i;j<strLen; j++){
                if(i==j)
                    dp[i][j] = 1; //是palindromic 
                else if((j-i)==1 && s[i]==s[j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        //端点间隔从2开始， 不断增加，最大为strLen-1
        for(int interval=2;interval<strLen;interval++){
            for(int begin=0;begin<=strLen-1-interval;begin++){
                int end = begin+interval;
                if(dp[begin+1][end-1]==1 && s[begin]==s[end]){
                    dp[begin][end]=1;
                }
            }
        }

        //寻找最长回文串端点
        int left,right;
        int flag=0;
        for(int intv=strLen-1;intv>=0;intv--){
            for(int i=0;i<=strLen-1-intv;i++){
                if(dp[i][i+intv]==1){
                    left=i;
                    right=i+intv;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }

        return s.substr(left,right);
    }
};







// 第二次写
class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() == 0) return s;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
    int longest = 1;
    int l=0, r=0;

    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 2;
        if (longest < dp[i][i + 1]) {
          longest = dp[i][i + 1];
          l = i;
          r = i + 1;
        }
      }
      else dp[i][i + 1] = 0;
    }

    for (int len = 2; len <= s.size() - 1; len++) {
      for (int i = 0; i < s.size() - 1; i++) {
        int j = i + len;
        if (j > s.size() - 1)
          break;
        else {
          if (dp[i + 1][j - 1] == 0 || s[i] != s[j]) dp[i][j] = 0;
          else {  // (s[i] == s[j]) 
            dp[i][j] = dp[i + 1][j - 1] + 2;
            if (longest < dp[i][j]) {
              longest = dp[i][j];
              l = i;
              r = j;
            }
          }
        }
      }
    }
    return s.substr(l, longest);
  }
};

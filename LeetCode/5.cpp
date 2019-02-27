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


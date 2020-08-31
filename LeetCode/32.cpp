class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;

        int i=0;
        while(i<=s.length()-2){
            if(s[i] == '('){
                int maxLen=0;
                while(i<=s.length()-2){
                    if(s[i]=='(' && s[i+1]==')'){
                        maxLen+=2;
                        i+=2;
                    }else{
                        res = max(maxLen,res);
                        i++;
                        break;
                    }
                }
            }else{
                i++;
            }
        }
        return res;
    }
};

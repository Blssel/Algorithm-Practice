class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        string explained = "";
        int i=0,j=0;
        while(i<sLen){
            if(s[i] == p[j] || p[j] == '.'){
                i++;
                j++;
            }else if(p[j] == '*'){ 
                if(s[i-1] != s[i]){ //重复零次，比较下一位
                    j++;
                    continue;
                }else{  //确定重复多少次,然后让i，j跳过去
                    char forRepeat = s[i];
                    while(s[i]==forRepeat){
                        
                    }
                }
                
            }else{
                return false;
            }
        }
    }
};

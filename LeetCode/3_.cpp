#include<map>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(strlen(s) == 0)
            return res;

        map<char, int> m;
        int tmpMax = 0;
        int begin = 0;
        for(int i=0; i<strlen(s); i++){
            if(m.find(s[i]) == m.end() || m[s[i]] < begin){
                m[s[i]] = i;
                tmpMax++;
            }else{
                if(tmpMax > res){
                    res = tmpMax;
                    tmpMax = i - m[s[i]];
                }
            }
        }
        res = tmpMax++;
        return tmpMax;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;     
        m['V'] = 5;     
        m['X'] = 10;      
        m['L'] = 50;      
        m['C'] = 100;     
        m['D'] = 500;     
        m['M'] = 1000;      
        
        int sLen = s.length();
        int res = 0;
        int i=0;
        while(i!=sLen){
            if(i!=sLen-1 && (  (s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X') )
                             ||(s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C') )
                             ||(s[i]=='C' && (s[i+1]=='D' ||s[i+1]=='M')  ))){
                printf("#######");
                res = res - m[s[i]] + m[s[i+1]];
                i += 2;
                continue;
            }else{
                res = res + m[s[i]];
                i++;
            }
        }
        return res;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sLen=s.length(),tLen=t.length();
        if(sLen != tLen)
            return false;
        
        map<char,char> m1;
        map<char,char> m2;
        int i=0;
        while(i!=sLen){
            if(m1.find(s[i]) == m1.end()){
                if(m2.find(t[i]) != m2.end()){
                    return false;
                }
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
                continue;
            }else if(m1[s[i]] != t[i]){ //if has the key
                return false;
            }else{
                i++;
            }
        }
        return true;
    }
};

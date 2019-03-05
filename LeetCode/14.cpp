class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size()
        string res="";
        int i=0;
        while(true){
            for(int j=0;j<len;j++){
                if(i==strs[j].length())
                    return res;
                if(j==0)
                    char c= strs[j][i];
                else if(strs[j][i] != c){
                    return res;
                }
            }
            res = res+strs[0][i];
            i++;
        }
        return res;
    }
};

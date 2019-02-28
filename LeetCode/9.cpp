class Solution {
public:
    bool isPalindrome(int x) {
        //整型最长也就9位十进制
        int integer[20];

        if(x<0) return false;

        int len=0;
        while(x!=0){
            int lowBit = x%10;
            x = x/10;
            integer[len++] = lowBit;
        }

        for(int i=0;i<len/2;i++){
            int j = len-1-i;
            if(integer[i] != integer[j])
                return false;
        }
        return true;
    }
};

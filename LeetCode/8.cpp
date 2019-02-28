class Solution {
public:
    int myAtoi(string str) {
        //去空白
        int p=0;
        while(str[p] == ' ')
            p++;
        //检查初始字符是否是数字，若不是，返回0
        if(str[p]!='+' && str[p]!='-' && str[p]<'0' && str[p]>'9')
            return 0;
        //正负号
        int sign=1;
        if(str[p]=='+'){
            sign=1;
            p++;
        }else if(str[p]=='-'){
            sign=-1;
            p++;
        }
        //开始转换
        int res=0;
        while(str[p]>='0' && str[p]<='9'){
            if(res>INT_MAX/10 || (res==INT_MAX/10 && str[p]-48>7)){
                return INT_MAX;
            }
            if(res<INT_MIN/10 || (res==INT_MIN/10 && str[p]-48>8)){
                return INT_MIN;   
            }
            res = res*10 + sign*(str[p]-48);
            p++;
        }
        return res;
    }
};


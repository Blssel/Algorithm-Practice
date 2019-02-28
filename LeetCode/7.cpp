class Solution {
public:
    int reverse(int x) {
        int rev;
        while(x!=0){
            int lowBit = x%10;
            x =x/10;
            if(rev>MAXINT/10 || (rev==MAXINT/10&&lowBit>7)) return 0;
            if(rev<MININT/10 || (rev==MININT/10&&lowBit<-8)) return 0;
            rev = rev*10 + lowBit;
        }
        return rev;
    }
};

















/*
// C++中如果发生类似int型溢出，是会直接报错的
class Solution {
public:
    int reverse(int x) {
        int xx = x;
        if(x<0) x=-1*x;
        stack<int> q1,q2;
        queue<int> q3;
        while(x>0){
            int b = x%10;
            q1.push(b);
            q2.push(b);
            x=x/10;
        }
        
        int factor=1;
        int reversed=0;
        while(!q1.empty()){
            int bb = q1.top();
            q1.pop();
            reversed += factor*bb;
            factor = factor*10;
        }
        int res = reversed;
        
        while(reversed>0){
            int bbb = reversed%10;
            q3.push(bbb);
            reversed=reversed/10;
        }
        
        // 检验是否相等
        while(!q2.empty()){
            int first = q2.top();
            q2.pop();
            int second = q3.front();
            q3.pop();
            if(first != second)
                if(xx<0 && -1*reversed == -1*pow(2,31)){
                    return -1*reversed;
                }else
                    return 0;
        }
        if(xx<0)
            return -1*res;
        else
            return res;
    }
};
*/

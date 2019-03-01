class Solution {
public:
    int getBase(int x){
        if(x>=1 && x<4)
            return 1;
        if(x>=4 && x<5)
            return 4;
        if(x>=5 && x<9)
            return 5;
        if(x>=9 && x<10)
            return 9;
        if(x>=10 && x<40)
            return 10;
        if(x>=40 && x<50)
            return 40;
        if(x>=50 && x<90)
            return 50;
        if(x>=90 && x<100)
            return 90;
        if(x>=100 && x<400)
            return 100;
        if(x>=400 && x<500)
            return 400;
        if(x>=500 && x<900)
            return 500;
        if(x>=900 && x<1000)
            return 900;
        return 1000; 
    }
    
    string intToRoman(int num) {
        map<int,string> m;
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
        
        string res = "";
        while(num>0){
            int base = getBase(num);
            num = num - base;
            res = res + m[base];
        }
        return res;
    }
};


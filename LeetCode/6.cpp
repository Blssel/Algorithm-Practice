#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || int(s.length())==0){
            return s;
        }
        vector<string> zigzag(min(numRows,int(s.length())));
        int i=0;
        bool goDown = true;
        for(int p=0;p<int(s.length());p++){
            zigzag[i] = zigzag[i] + s[p];
            if(goDown == true) i++;
            else i--;
            if(i==0) goDown=true;
            if(i==numRows-1) goDown=false;
        }
        string res = "";
        for(int q=0;q<zigzag.size();q++){
            res += zigzag[q];
        }
        return res;
    }
};


int main(){
    string s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int numRows = 2;
    Solution slt;
    string res = slt.convert(s,numRows);
    //printf("%s",res);
    cout<<endl;
    cout<<endl<<res<<endl;



    return 0;
}



/*
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()==0 || s.length()==1 || numRows==1 || s.length()<numRows)
            return s;
        char ss[s.length()+1];
        int p=0;
        for(int i=0;i<numRows;i++){

            int begin = i;
            if(i==0 || i==numRows-1){
                ss[p++] = s[begin];
                printf("%c",s[begin]);
                int next = begin;
                while(true){
                    next = next + (2*numRows-2);
                    if(next<s.length()){
                        ss[p++] = s[next];
                        printf("%c",s[next]);
                    }else{
                        printf("#############");
                        break;
                    }
                }
            }else{
                ss[p++] = s[begin];
                printf("%c",s[begin]);
                int next = begin;
                while(true){
                    next = next + 2*(numRows-(i+1));
                    if(next<s.length()){
                        ss[p++] = s[next];
                        printf("%c",s[next]);
                    }else{
                        break;
                    }
                    next = next + (2*numRows-2) - 2*(numRows-(i+1));
                    if(next<s.length()){
                        ss[p++] = s[next];
                        printf("%c",s[next]);
                    }else{
                        break;
                    }
                }
            }
        }
        //ss[s.length()] = '\0';
        string res(ss);
        return res;
    }
};

int main(){
    string s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int numRows = 2;
    Solution slt;
    string res = slt.convert(s,numRows);
    //printf("%s",res);
    cout<<endl;
    cout<<endl<<res<<endl;



    return 0;
}
*/









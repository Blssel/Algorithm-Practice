class Solution {
public:
    int factorial(int x){
      if(x==0)
          return 1;
      else
          return x*factorial(x-1);
    }

    string getPermutation(int n, int k) {
        k = k-1;
        string res="";
        vector<char> v;
        for(int i=0; i<n;i++){
            v.push_back(i + 49);
        }

        for(int i=1;i<=n;i++){
            int fac = factorial(n-i);
            int group = k/fac;
            k = k%fac;
            res = res + v[group];
            v.erase(v.begin()+group);
        }
        return res;
    }
};

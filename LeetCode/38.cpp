class Solution {
public:
  string countAndSay(int n) {
    string res = "1";
    if (n == 1) return res;
    for (int i = 2; i <= n; i++) {
      string tmp = "";
      int p = 0;
      int num = 0;
      while (p < res.length()) {
        num++;
        if (p == res.length() - 1 || res[p + 1] != res[p]) {
          char t[12];
          int l = sprintf(t, "%d", num);
                    //cout<<t<<endl;
                    //cout<<res<<endl;
                    //cout<<p<<endl;
                    //cout<<res.substr(p)<<endl;
          tmp = tmp + t +res.substr(p,1);
          num = 0;
        }
        p++;
      }
      res = tmp;
            //cout<<res<<endl;
    }
    return res;
  }
};

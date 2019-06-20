class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> v(n, vector<int>(n));
    int num = 1;
    for (int begin = 0; begin < n / 2; begin++) {
            //cout<<"##########"<<endl;
      for (int j = begin; j <= n - 2 - begin; j++) {
                //cout<<num<<endl;
        v[begin][j] = num++;
      }
      for (int i = begin; i <= n - 2 - begin; i++) {
                //cout<<num<<endl;
        v[i][n - 1 - begin] = num++;
      }
      for (int j = n - 1 - begin; j >= begin + 1; j--) {
                //cout<<num<<endl;
        v[n - 1 - begin][j] = num++;
      }
      for (int i = n - 1 - begin; i >= begin + 1; i--) {
                //cout<<num<<endl;
        v[i][begin] = num++;
      }
    }
    if (n % 2 == 1) {
      v[n / 2][n / 2] = num;
    }
    return v;
  }
};

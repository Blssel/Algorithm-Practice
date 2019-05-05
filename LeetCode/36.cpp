class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int mark[10];
    for (int i = 0; i < 9; i++) {
      for (int k = 0; k < 10; k++) mark[k] = 0;
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        else {
          int num = board[i][j] - '0';
          mark[num]++;
          if (mark[num] > 1) {
            cout << "1111111";
            return false;
          }
        }
      }
    }
    for (int i = 0; i < 9; i++) {
      for (int k = 0; k < 10; k++) mark[k] = 0;
      for (int j = 0; j < 9; j++) {
        if (board[j][i] == '.') continue;
        else {
          int num = board[j][i] - '0';
          mark[num]++;
          if (mark[num] > 1) {
            cout << "2222222";
            return false;
          }
        }
      }
    }
    for (int i = 0; i < 7; ) {
      for (int j = 0; j < 7;) {
        for (int k = 0; k < 10; k++) mark[k] = 0;
        for (int m = i; m < i + 3; m++) {
          for (int n = j; n < j + 3; n++) {
            if (board[m][n] == '.') continue;
            else {
              int num = board[m][n] - '0';
              mark[num]++;
              if (mark[num] > 1) {
                cout << "3333333" << endl;
                cout << i << " " << j << endl;
                cout << m << " " << n << endl;
                cout << num << endl;
                return false;
              }
            }
          }
        }
        j = j + 3;
      }
      i = i + 3;
    }
    return true;
  }
};

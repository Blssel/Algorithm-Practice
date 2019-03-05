class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int height = board.size();
    if (height == 0) return;
    int width = board[0].size();
    queue<pair<int, int>> q;

    vector<int> ii, jj;
    for (int i = 0; i < height; i++) {
      ii.push_back(i);
      jj.push_back(0);
    }
    for (int i = 0; i < height; i++) {
      ii.push_back(i);
      jj.push_back(width - 1);
    }
    for (int j = 0; j < width; j++) {
      ii.push_back(0);
      jj.push_back(j);
    }
    for (int j = 0; j < width; j++) {
      ii.push_back(height - 1);
      jj.push_back(j);
    }

    for (int k = 0; k < ii.size(); k++) {
      int i = ii[k];
      int j = jj[k];
      if (board[i][j] == 'O') {
        // bfs
        q.push(pair<int, int>(i, j));
          while (!q.empty()) {
            pair<int, int> tmp = q.front();
              q.pop();
              int x = tmp.first, y = tmp.second;
              board[x][y] = 'V'; //mark visited
              if (x != 0 && board[x - 1][y] == 'O')
                q.push(pair<int, int>(x - 1, y));
              if (x != height - 1 && board[x + 1][y] == 'O')
                q.push(pair<int, int>(x + 1, y));
            if (y != 0 && board[x][y - 1] == 'O')
              q.push(pair<int, int>(x, y - 1));
            if (y != width - 1 && board[x][y + 1] == 'O')
              q.push(pair<int, int>(x, y + 1));
          }
      }
    }



    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        else if (board[i][j] == 'V')
          board[i][j] = 'O';
      }
    }
  }
};

int main(){
    Solution s;
    s.solve()
    return 0;
}

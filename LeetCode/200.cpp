class Solution {
public:
  void bfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    for (int i = x - 1; i >= 0 && grid[i][y] == '1' && !vis[i][y]; i--) {
      vis[i][y] = true;
      bfs(grid, i, y, vis);
    }
    for (int i = x + 1; i < grid.size() && grid[i][y] == '1' && !vis[i][y]; i++) {
      vis[i][y] = true;
      bfs(grid, i, y, vis);
    }
    for (int j = y - 1; j >= 0 && grid[x][j] == '1' && !vis[x][j]; j--) {
      vis[x][j] = true;
      bfs(grid, x, j, vis);
    }
    for (int j = y + 1; j < grid[0].size() && grid[x][j] == '1' && !vis[x][j]; j++) {
      vis[x][j] = true;
      bfs(grid, x, j, vis);
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();
    // if (cols == 0) return 0;
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    int res = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j]=='1' && !vis[i][j]) {
          res++;
          bfs(grid, i, j, vis);
        }
      }
    }
        return res;
  }
};

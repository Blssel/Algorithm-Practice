class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int column = grid[0].size();

        vector<vector<int>> dp;
        dp.resize(rows);
        for(int i=0;i<rows;i++){
            dp[i].resize(column);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                dp[i][j] = -1;
            }
        }

        int res = helper(grid, dp, 0, 0, rows-1, column-1);
        return res;
    }

    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int start_x, int start_y, int end_x, int end_y){
        cout<<dp.size()<<dp[0].size()<<endl;
        if(dp[start_x][start_y]!=-1) return dp[start_x][start_y];
        if(start_x==end_x){
            //printf("@@@@@@@@@\n");
            int minSum = 0;
            for(int j=start_y;j<=end_y;j++){
                minSum += grid[start_x][j];
            }
            dp[start_x][start_y] = minSum;
            return minSum;
        }
        if(start_y==end_y){
            //printf("###################\n");
            int minSum = 0;
            for(int i=start_x;i<=end_x;i++){
                minSum += grid[i][start_y];
            }
            dp[start_x][start_y] = minSum;
            return minSum;
        }
        int sumRight, sumDown;
        //printf("&&&&&&&&&&&&&&\n");
        sumRight = helper(grid, dp, start_x, start_y+1, end_x, end_y);
        //printf("*********\n");
        sumDown = helper(grid, dp, start_x+1, start_y, end_x, end_y);
        int minSum = min(sumRight, sumDown) + grid[start_x][start_y];
        dp[start_x][start_y] = minSum;
        return minSum;
    }
};


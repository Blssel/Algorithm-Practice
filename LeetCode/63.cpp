class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        if(obstacleGrid[rows-1][column-1]==1||obstacleGrid[0][0]==1)
            return 0;
        int dp[110][110];
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++)
                dp[i][j]=-1;
        }
        int res = helper(obstacleGrid, dp, 0, 0, rows-1, column-1);
        return res;
        
    }
    int helper(vector<vector<int>>& obstacleGrid, int dp[110][110], int start_x, int start_y, int end_x, int end_y){
        if(dp[start_x][start_y]!=-1) return dp[start_x][start_y];
        if(start_x==end_x){
            for(int j=start_y+1; j<end_y; j++){
                if(obstacleGrid[start_x][j]==1) {
                    dp[start_x][start_y] = 0;
                    return 0;
                }
            }
            dp[start_x][start_y] = 1;
            return 1;
        }
        if(start_y==end_y){
            for(int i=start_x+1; i<end_x; i++){
                if(obstacleGrid[i][start_y]==1) {
                    dp[start_x][start_y] = 0;
                    return 0;
                }
            }
            dp[start_x][start_y] = 1;
            return 1;
        }
        
        int pathsRight=0,pathsDown=0;
        if(obstacleGrid[start_x][start_y+1]!=1)
            pathsRight = helper(obstacleGrid, dp, start_x, start_y+1, end_x, end_y);
        if(obstacleGrid[start_x+1][start_y]!=1)
            pathsDown = helper(obstacleGrid, dp, start_x+1, start_y, end_x, end_y);
        dp[start_x][start_y] = pathsRight + pathsDown;
        return pathsRight + pathsDown;


    }
};


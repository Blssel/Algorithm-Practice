class Solution {
public:
    int helper(int start_x, int start_y, int end_x, int end_y, int dp[110][110]){
        if(dp[start_x][start_y]!=0){
            return dp[start_x][start_y];
        }
        //printf("@@@@@\n");
        if(start_x==end_x || start_y==end_y){
            //printf("$$$$$$$$\n");
            return 1;
        }
        int pathsRight=0, pathsDown=0;
        if(start_x<end_x){
            pathsRight = helper(start_x,start_y+1,end_x,end_y,dp);
        }
        if(start_y<end_y){
            pathsDown = helper(start_x+1,start_y,end_x,end_y,dp);
        }
        dp[start_x][start_y]=pathsDown+pathsRight;
        return pathsDown+pathsRight;
    }

    int uniquePaths(int m, int n) {
        if(m==1&&n==1) return 1;
        int dp[110][110];
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++)
                dp[i][j]=0;
        }
        return helper(0,0,m-1,n-1,dp);
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     int m = obstacleGrid.size();
     int n = obstacleGrid[0].size();
     vector<vector<int>> dp(m,vector<int>(n,0));
     for(int i=0;i<m;i++)
        {
         for(int j=0;j<n;j++)
            {
             int up = 0,left = 0;
             if(i>0 && !obstacleGrid[i][j]) up = dp[i-1][j];
             if(j>0 && !obstacleGrid[i][j]) left = dp[i][j-1];
             if(i==0 && j==0 && !obstacleGrid[i][j]) dp[i][j]=1;
             else dp[i][j] = (up + left);
            }
        }
     return dp[m-1][n-1];   
    }
};

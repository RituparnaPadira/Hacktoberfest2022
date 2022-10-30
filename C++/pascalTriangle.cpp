class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     int n = numRows;
     vector<vector<int>> dp(n,vector<int>(n,0));    
     for(int i=0;i<n;i++)
        {
         dp[i][0] = 1;
         dp[i][i] = 1;
        }
     for(int i=2;i<n;i++)
        {
         for(int j=1;j<n-1;j++)
            {
             dp[i][j] = dp[i-1][j] + dp[i-1][j-1];  
            }
        }
     vector<vector<int>> ans;
     for(int i=0;i<n;i++)
        {
         vector<int> temp; 
         for(int j=0;j<i+1;j++)
            {
             temp.push_back(dp[i][j]);  
            }
         ans.push_back(temp);   
        }
     return ans;     
    }
};

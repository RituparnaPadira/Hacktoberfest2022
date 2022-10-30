class Solution {
public:
    int climbStairs(int n) {
     vector<int> dp(n+1,0);
     dp[0] = 1;
     dp[1] = 1;
     for(int i=2;i<=n;i++)
        {
         int os = dp[i-1];
         int ts = dp[i-2];
         dp[i] = os + ts;
        }
     return dp[n];   
    }
};

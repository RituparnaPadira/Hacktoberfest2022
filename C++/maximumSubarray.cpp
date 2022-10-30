class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int s = 0;
     int mx = INT_MIN;
     int n = nums.size();
     for(int i=0;i<n;i++)
        {
         s += nums[i];
         mx = max(mx,s);
         if(s < 0) s = 0;   
        }
     return mx;
    }
};

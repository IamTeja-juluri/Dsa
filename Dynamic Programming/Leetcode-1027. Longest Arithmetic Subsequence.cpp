class Solution {
public:
  
    int longestArithSeqLength(vector<int>& nums) {
        
      
//         int ans=1;
//        unordered_map<int,int> mp[n]; gives tle
        
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 int diff=nums[i]-nums[j];
//                 mp[i][diff]=mp[j][diff]+1;
//                 ans=max(ans,mp[i][diff]);
//             }
//         }
        int n=nums.size(),ans=0,dp[1001][1001]={}; 
        
        // dp[i][j] => number of elements before index i, forming an AP with difference j (technically j-500)
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                //since difference can be negative too, and constraints are [0,500], we add 500
                // to the difference between nums[i] and nums[j]
                int d=nums[i]-nums[j]+500;
                
                dp[i][d]=dp[j][d]+1;
                ans=max(ans,dp[i][d]);
            }
        }
        
        return ans+1;
    }
};

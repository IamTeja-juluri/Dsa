class Solution {
public:
    
    vector<int> dp;
    
    int maxPartitionSum(vector<int>&arr,int k,int idx){
     
        int n=arr.size();
        
        if(idx>=n)
            return 0;
       
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=INT_MIN;
        
        int maxi=INT_MIN;
        
            for(int j=0;j<k && (idx+j)<n;j++){
                maxi=max(arr[idx+j],maxi);
                int subprob=maxi*(j+1)+maxPartitionSum(arr,k,idx+j+1);
                ans=max(ans,subprob);
            }
       
       return dp[idx]=ans; 
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       
        int n=arr.size();
        
        dp.resize(n+1,-1);
        
        return maxPartitionSum(arr,k,0);
        
    }
};

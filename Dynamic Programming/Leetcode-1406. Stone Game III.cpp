//app1
class Solution {
public:
    
    
    vector<int> dp;
    
    int helper(vector<int>&nums,int idx,int n){
        
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
         int ans=INT_MIN;
        
         ans=max(ans,nums[idx]-helper(nums,idx+1,n));
        
         if(idx<(n-1))
            ans=max(ans,nums[idx]+nums[idx+1]-helper(nums,idx+2,n));
        
         if(idx<(n-2))
            ans=max(ans,nums[idx]+nums[idx+1]+nums[idx+2]-helper(nums,idx+3,n));
        
     
        return dp[idx]=ans;
        
    }
    
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n=stoneValue.size();
        
      
        dp.resize(n+10,-1);
        
        string ans="Tie";
        
        int diff=helper(stoneValue,0,n);
        
        
        if(diff>0)
            ans="Alice";
         
        if(diff<0)
            ans="Bob";
        
        return ans;
    }
};
//app2
class Solution {
public:
    int dp[50000+10][2];
    int knapsack(vector<int>&arr,int i,int j,
                 int chance)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][chance]!=-1)
            return dp[i][chance];
        if(chance==0)
        {
            int x=INT_MIN,y=INT_MIN,z=INT_MIN;
            if(i<arr.size())
            {
                x=arr[i]+knapsack(arr,i+1,j,1);
            }
            if(i+1<arr.size())
            {
                y=arr[i]+arr[i+1]+knapsack(arr,i+2,j,1);
            }
            if(i+2<arr.size())
            {
                z=arr[i]+arr[i+1]+arr[i+2]+knapsack(arr,i+3,j,1);
            }
          
            return dp[i][chance]= max(max(x,y),z);
        }
        if(chance==1)
        {
            int x=INT_MAX,y=INT_MAX,z=INT_MAX;
            if(i<arr.size())
            {
                x=knapsack(arr,i+1,j,0);
            }
            if(i+1<arr.size())
            {
                y=knapsack(arr,i+2,j,0);
            }
            if(i+2<arr.size())
            {
                z=knapsack(arr,i+3,j,0);
            }
            return dp[i][chance]= min(min(x,y),z);
            
        }
        return 0;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto i : stoneValue)
        {
            sum+=i;
        }
        int x=knapsack(stoneValue,0,stoneValue.size()-1,0);
        
        if(sum-2*x<0)
            return "Alice";
        if(sum-2*x==0)
            return "Tie";
        return "Bob";
        
    }
};

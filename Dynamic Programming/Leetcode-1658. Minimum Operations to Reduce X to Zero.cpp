//Gives TLE
class Solution {
public:
    
    vector<vector<int>>dp; 
    
    int findMin(vector<int>&nums,int x,int i,int j,int c){
        
        if(x==0)
          return c;   
        
        if(i>j || x<0)
            return INT_MAX;
        
         if(dp[i][j]!=-1)
            return dp[i][j];
       
        int l1=findMin(nums,x-nums[i],i+1,j,c+1);
    
        int r1=findMin(nums,x-nums[j],i,j-1,c+1);
    
        return dp[i][j]=min(l1,r1);   
    }

    
    
    int minOperations(vector<int>& nums, int x) {
     
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        int ans=findMin(nums,x,0,n-1,0);
        return ans==INT_MAX?-1:ans;
    }
};

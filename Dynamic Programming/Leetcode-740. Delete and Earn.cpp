//similar to house rober
class Solution {
public:
     
     vector<int> dp;
    
    int maximizePoints(vector<int>&arr,int idx,int n){
        
        if(idx>n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int op1=INT_MIN;
        
        if(arr[idx]>0)
            op1=arr[idx]+maximizePoints(arr,idx+2,n);
       
        int op2=maximizePoints(arr,idx+1,n);
        return dp[idx]=max(op1,op2);
    }
    
    int deleteAndEarn(vector<int>& nums) {
     
        int maxele=*max_element(nums.begin(),nums.end());
        dp.resize(maxele+1,-1);
        
        vector<int> arr(maxele+1,0);
        
        for(auto x:nums)
            arr[x]+=x;
        
        return maximizePoints(arr,0,maxele);
    }
};

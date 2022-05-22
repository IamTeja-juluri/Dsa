class Solution {
public:
    
    vector<vector<int>  > dp;
    
     int maximizeProfit(int start,vector<int>&nums,vector<int>&m,int idx){
          
        if(idx==m.size())
            return 0;
        
        
        if(dp[start][idx]!=-1)
            return dp[start][idx];
         
         int end=nums.size()-1-idx+start;
    
         int op1=m[idx]*nums[start]+maximizeProfit(start+1,nums,m,idx+1);
         int op2=m[idx]*nums[end]+maximizeProfit(start,nums,m,idx+1);
       
        
        return dp[start][idx]=max(op1,op2);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
     
       int n=nums.size();   
       int m=multipliers.size(); 
        
       //since we know m cannot cross n , m is enough 
       dp.resize(m,vector<int>(m,-1)) ;
        
        return maximizeProfit(0,nums,multipliers,0);
        
    }
};

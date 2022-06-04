//dp gives tle
class Solution {
public:
    
    vector<int>dp;

    int maxScore(vector<int>&nums,int k,int idx){
        
        int n=nums.size();
        
         if(dp[idx]!=-1)
            return dp[idx];
        
        if(idx==n-1)
            return nums[idx];
        
        
        int score=INT_MIN;
        
        for(int i=idx+1;i<=idx+k;i++){
            
            if(i>=n){
                continue;
            }
             
            score=max(score,nums[idx]+maxScore(nums,k,i));
        }     
        
        return dp[idx]=score;
    }
    
    
    int maxResult(vector<int>& nums, int k) {
     
        int n=nums.size();
         dp.resize(n+k+2,-1);
        
        return maxScore(nums,k,0);

    }
};

//using heaps+dp gives ac
class Solution {
public:
  
    
    int maxResult(vector<int>& nums, int k) {
     
        int n=nums.size();
         
       priority_queue<pair<int,int> > pq;
        
        pq.push({nums[0],0});
        int score=nums[0];
        
        for(int i=1;i<n;i++){
            
            while(pq.top().second<(i-k))
                pq.pop();
            
            score=nums[i]+pq.top().first;
            pq.push({score,i});
            
        }

        
        return score;
    }
};

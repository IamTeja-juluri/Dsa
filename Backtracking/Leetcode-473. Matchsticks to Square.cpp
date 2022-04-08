class Solution {
public:
    
   
    long long int visited;
    
    bool canmakeSquare(vector<int>&nums,int idx,int currSum,int targetSum,int k,int visited){
        
        if(k==1)
            return true;
        
        if(targetSum==currSum)   
            return canmakeSquare(nums,0,0,targetSum,k-1,visited);
        
        
        for(int j=idx;j<nums.size();j++){
            if( (visited&(1<<j)) || (currSum+nums[j])>targetSum)
                continue;
            visited=visited|(1<<j);
             bool res=canmakeSquare(nums,j+1,currSum+nums[j],targetSum,k,visited);
             if(res)
                 return true;
            visited=visited^(1<<j);
        }
    
        return false;
        
    }
    
    
    
    bool makesquare(vector<int>& matchsticks) {
        
        int sum=0;
        int n=matchsticks.size();
        
        for(auto x:matchsticks)
            sum+=x;
        
        if(n<4 || sum%4)
            return false;
        
        long long int visited=0;
        visited=0;
        
        return canmakeSquare(matchsticks,0,0,sum/4,4,visited);
        
    }
};

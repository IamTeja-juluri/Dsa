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
//another way for bitmasking
class Solution {
public:
    long long int mask;
    
    bool solve(vector<int> &matchsticks, int target, long long mask, int currSum, int i, int k){
        if(k==1) 
            return true; 
        
        if(currSum==target) 
                return solve(matchsticks, target, mask, 0, 0, k-1);  
        
        for(int j=i; j<matchsticks.size(); j++){ 
            
            if((mask&(1<<j))==0 || currSum+matchsticks[j]>target) 
                continue;
            
            mask=mask&(~(1<<j));  
            if(solve(matchsticks, target, mask, currSum+matchsticks[j], j+1, k))  
                return true;
            mask=mask|(1<<j); 
            
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if(matchsticks.size()<4||sum%4)
            return false; 
         mask=(1<<matchsticks.size())-1; 
        
        return solve(matchsticks, sum/4, mask, 0, 0, 4); 
    }
};










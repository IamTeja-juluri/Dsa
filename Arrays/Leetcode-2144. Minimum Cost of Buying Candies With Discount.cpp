class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int cost=0;
        
        if(n==1)
            cost=nums[0];
        
        else if(n==2)
            cost=nums[0]+nums[1];
        
        else{
            int p1=n-2,p2=n-1;
            
            while(p1>=0){
             cost=cost+nums[p2]+nums[p1];
              p2=p2-3;
              p1=p1-3; 
            }
            
            if(p2==0)
                cost=cost+nums[p2];
            
        }
    
        return cost;
    }
};

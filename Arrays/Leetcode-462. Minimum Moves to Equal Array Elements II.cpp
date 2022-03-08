class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        
        int n=nums.size();
        int median=n/2;
        
        sort(nums.begin(),nums.end());
        int cost=0;
        
        for(int i=0;i<n;i++)
            cost=cost+abs(nums[median]-nums[i]);
        
        return cost;
        
    }
};

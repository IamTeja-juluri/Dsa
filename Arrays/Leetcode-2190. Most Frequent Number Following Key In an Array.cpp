class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        
        int count=0,ans=0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
            
        }
        
        
        for(int i=0;i<=nums.size()-2;i++){
            
            if(nums[i]==key){
                
                mp[nums[i]]-=1;
               
                if(count<mp[nums[i+1]]){
                    count=mp[nums[i+1]];
                    ans=nums[i+1];
                }
                
                mp[nums[i]]+=1;
            }
            
        }
        
        
        return ans;
    }
};

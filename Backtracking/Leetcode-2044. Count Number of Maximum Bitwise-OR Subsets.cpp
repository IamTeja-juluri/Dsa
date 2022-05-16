class Solution {
public:
    
    map<int,int> mp;
    
    void subsets(vector<int>&nums,int idx,int val){
        
        if(idx==nums.size()){
            mp[val]+=1;
            return;
        }
        
        int temp=val;
        val=val|nums[idx];
        subsets(nums,idx+1,val);
        val=temp;
        subsets(nums,idx+1,val);
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        subsets(nums,0,0);
        auto it=mp.end();
        it=--it;
        int ans=(*it).second;
        return ans;
        
    }
};

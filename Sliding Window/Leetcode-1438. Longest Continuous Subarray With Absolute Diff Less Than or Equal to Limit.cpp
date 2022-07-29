class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int j=0;
        
        int n=nums.size();
        int ans=0;
       multiset<int> m;
        
        
        for(int i=0;i<n;i++){
            m.insert(nums[i]);
            auto it1=m.begin();
            auto it2=--m.end();
            while(*it2-*it1>limit){
                m.erase(m.find(nums[j]));
                it1=m.begin();
                it2=--m.end();
                j+=1;
            }
           ans=max(ans,i-j+1);
        }
        
        
        return ans;
    }
};

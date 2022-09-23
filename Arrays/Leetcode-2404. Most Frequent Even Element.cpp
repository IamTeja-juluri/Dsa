class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(auto x:nums)
            if(x%2==0)
                mp[x]+=1;
        
        int ans=-1;
        int freq=0;
        
        for(auto it:mp){
            if(freq<it.second){
                freq=it.second;
                ans=it.first;
            }
        }
        
        return ans;
    }
};

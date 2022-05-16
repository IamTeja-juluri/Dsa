class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        map<int,int>mp;
        int n=nums.size();
        
        for(int i=0;i<(1<<n);i++){
            int ans=0;
            for(int j=0;j<n;j++){
                if((1<<j)&i)
                    ans=ans|nums[j];
            }
            mp[ans]+=1;
        }
        
        int res=0;
        
        auto it=mp.end();
        it=--it;
        res=it->second;
        
        return res;
    }
};

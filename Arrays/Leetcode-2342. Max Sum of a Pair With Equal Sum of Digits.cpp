class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        
        unordered_map<int,vector<int> >mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            int x=nums[i];
            while(x!=0){
                sum+=x%10;
                x/=10;
            }
            mp[sum].push_back(nums[i]);
        }
        
        for(auto x:mp){
            if(x.second.size()>1){
                int n=x.second.size();
                sort(x.second.begin(),x.second.end());
                ans=max(ans,x.second[n-1]+x.second[n-2]);
            }
        }
        
        return ans;
    }
};

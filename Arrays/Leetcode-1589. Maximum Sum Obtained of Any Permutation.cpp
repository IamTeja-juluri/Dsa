class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& rq) {
        
        int n=nums.size();
        
        int r=rq.size();
        
        int mod=1e9+7;
      
        vector<long> count(n,0);
        
        //trick to fill count array
        //filling count array in conventional way gives tle because for n requests it takes n * n time to fill
        for(int i=0;i<r;i++){
           
            count[rq[i][0]]+=1;
            if(rq[i][1]+1<n)
                count[rq[i][1]+1]-=1;
         
        }
        
        for(int i=1;i<n;i++)
            count[i]=count[i]+count[i-1];
        
        sort(count.begin(),count.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        
        long ans=0;
        
        for(int i=0;i<n;i++){
            if(count[i]==0)
                break;
            ans+=(long)(count[i]*nums[i])%mod;
            ans%=mod;
        }
        
        return (int)ans;
    }
};

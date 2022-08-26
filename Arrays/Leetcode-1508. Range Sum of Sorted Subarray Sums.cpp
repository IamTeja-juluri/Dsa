class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
    
       int mod=1e9+7;
       vector<int> pref;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                sum%=mod;
                pref.push_back(sum);
            }
        }
        pref.push_back(0);
        
       sort(pref.begin(),pref.end());
        long long sum=0;
        
        for(int i=left;i<=right;i++){
            sum=(sum+pref[i])%mod;
        }
        
        return sum;
        
    }
};

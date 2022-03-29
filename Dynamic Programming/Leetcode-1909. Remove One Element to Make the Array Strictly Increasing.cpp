class Solution {
public:
    bool canBeIncreasing(vector<int>&a) {
        
        int n=a.size();
        vector<int>dp(n,1);
        int i=1,j=0;
        int len=0;
        
        while(i<n){
            while(j<i){
            if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+1);
              j++;
            }
            j=0;
            len=max(len,dp[i]);
            i++;
        }
        
        return len>=n-1;
    }
};

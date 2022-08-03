class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n=arr.size();
        
        int sum=0,j=0;
        vector<int>dp;
        dp.resize(n+1,INT_MAX);
        int len=INT_MAX;
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[j];
                j+=1;
            }
            if(sum==target){
               int curr_len=i-j+1;
               if(j>0 and dp[j-1]!=INT_MAX)
                   ans=min(ans,curr_len+dp[j-1]);
                len=min(len,curr_len);
            }
            dp[i]=len;
        }
        
        return ans==INT_MAX?-1:ans;
    }
};

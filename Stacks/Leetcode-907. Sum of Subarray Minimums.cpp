class Solution {
public:
    //idea is to check for occurences of every number in subarrays
    //to find it we find idx of nse on right and pse on left
    //and multiplying dem with by adding 1 gives us number of subarrays that
    //particular element is part of
    int sumSubarrayMins(vector<int>&nums) {
        
        stack<int>st1,st2;
        int n=nums.size();
        vector<long int>nse(n),pse(n);
        
        //imp to handle base conditions
        for(int i=0;i<n;i++){
            nse[i]=n-i-1;
            pse[i]=i;
        }
        int mod=1e9+7;
        
        //nse-next smaller element
        //pse prev smaller element
        //next smaller element
        
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[i]<nums[st1.top()]){
                nse[st1.top()]=i-st1.top()-1; //stores number of elements on right
                st1.pop();
            }
            st1.push(i);
        }
        
        //previous smaller element
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[i]<=nums[st2.top()]){
                pse[st2.top()]=st2.top()-i-1; //stores number of elements on left
                st2.pop();
            }
            st2.push(i);
        }
        
        long int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i]*(pse[i]+1)*(nse[i]+1);
            sum%=mod;
        }
        
        
        return sum;
    }
};

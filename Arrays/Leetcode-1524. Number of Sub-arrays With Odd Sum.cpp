class Solution {
public:
    
   
    
    int numOfSubarrays(vector<int>& arr) {
        
        int n=arr.size();
        
        int s=0;
        int cnt=0;
        int evencnt=0,oddcnt=0;
        int mod=(1e9+7);
        
        for(auto x:arr){
            s+=x;
            if(s%2){
                cnt=(cnt+1+evencnt)%mod;
                oddcnt=(oddcnt+1)%mod;
            }
            else{
                cnt=(cnt+oddcnt)%mod;
                evencnt=(evencnt+1)%mod;
            }
        }
        
        
        
        
        return cnt;
    }
};

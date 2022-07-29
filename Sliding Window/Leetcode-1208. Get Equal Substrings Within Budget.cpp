class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
     
        int j=0;
        int n=s.size();
        int window_cost=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            window_cost+=abs(s[i]-t[i]);
            while(window_cost>maxCost){
                window_cost=window_cost-abs(s[j]-t[j]);
                j+=1;
            }
            ans=max(ans,i-j+1);
        }
    
        return ans;
    }
};

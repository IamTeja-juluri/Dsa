class Solution {
public:
    int maxPower(string s) {
        
        int len=1;
        int ans=1;
        int n=s.size();
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                len+=1;
            }
            else{
                ans=max(ans,len);
                len=1;
            }
        }
        
        ans=max(ans,len);
        return ans;
    }
};

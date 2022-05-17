//LIS variation
class Solution {
public:
    
    static bool compare(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    
    bool isValid(string &s1,string &s2){
        
        int n=s1.size();
        int m=s2.size();
        
        if( (n+1)!=m)
            return false;
        
        int i=0,j=0;
        
        for(;j<m;){
            if(s1[i]==s2[j]){
                i+=1;
                j+=1;
            }
            else
                j+=1;
        }
        
        return ((i==n) && (j==m));
    }
    

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        
        int n=words.size();
        vector<int> dp(n,1);
        int ans=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i]) && dp[i] < dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};

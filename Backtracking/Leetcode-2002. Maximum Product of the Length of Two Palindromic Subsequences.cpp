class Solution {
public:
    
    int ans;
    
    bool isPalindrome(string &s){
        
        int l=0,r=s.length()-1;
        
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l+=1;
            r-=1;
        }
    
        return true;
    }
    
    
    void dfs(string &s,string &s1,string &s2,int idx){
        
        if(idx>=s.length()){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int n1=s1.size();
                int n2=s2.size();
                ans=max(ans,n1*n2);
            }
            return;
        }
        
        s1.push_back(s[idx]);
        dfs(s,s1,s2,idx+1);
        s1.pop_back();
        
        s2.push_back(s[idx]);
        dfs(s,s1,s2,idx+1);
        s2.pop_back();
        
        dfs(s,s1,s2,idx+1);
    }
   
    
    int maxProduct(string s) {
        ans=0;
        string a="",b="";
        dfs(s,a,b,0);
        return ans;
    }
};

class Solution {
public:
    
    bool isValid(int count[],int n){
        if(count['Q'-'A']<=(n/4) and count['W'-'A']<=(n/4) and count['E'-'A']<=(n/4) and count['R'-'A']<=(n/4))
            return true;
        return false;
    }
    
    
    int balancedString(string s) {
        
        
        int n=s.size();
        int count[26]={0};
        
        for(auto x:s)
            count[x-'A']+=1;
        
          if(count['Q'-'A']==(n/4) and count['W'-'A']==(n/4) and count['E'-'A']==(n/4) and count['R'-'A']==(n/4))
            return 0;
        
        
        int j=0,ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            count[s[i]-'A']-=1;
            while(j<=i and isValid(count,n)){
               ans=min(ans,i-j+1);
               count[s[j]-'A']+=1;
                j+=1;
            }
        }
        
        
        return ans==INT_MAX?-1:ans;
    }
};

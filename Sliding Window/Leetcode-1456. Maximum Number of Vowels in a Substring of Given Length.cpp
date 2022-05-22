class Solution {
public:
    int maxVowels(string s, int k) {
        
        int ans=0;
        int len=0;
        
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                len+=1;
        }
        
        ans=len;
       
        for(int i=0,j=k;j<s.size();i++,j++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                len-=1;
             if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                len+=1;
             ans=max(ans,len);    
           
        }
        
        return ans;
    }
};

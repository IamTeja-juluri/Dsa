class Solution {
public:
    
    int getMax(int count[]){
        
        int maxi=0;
        
        for(int i=0;i<26;i++)
            maxi=max(maxi,count[i]);
        
        return maxi;
    }
    
    
    int characterReplacement(string s, int k) {
        
        int j=0;
        int count[26]={0};
        int ans=0;
     
        for(int i=0;i<s.size();i++){
            
           count[s[i]-'A']+=1;
           int maxFreq=getMax(count);
           while(i-j+1 - maxFreq > k){
               count[s[j]-'A']-=1;
               j+=1;
           } 
            
           ans=max(ans,i-j+1);
        }
   
        return ans;
    }
};

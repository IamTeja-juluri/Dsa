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

//java
class Solution {
    public int maxVowels(String s, int k) {
     
         int ans=0;
        int len=0;
        
    
        
        for(int i=0;i<k;i++){
            
            char ch=s.charAt(i);
            
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                len+=1;
        }
        
        ans=len;
       
        for(int i=0,j=k;j<s.length();i++,j++){
            
            char ch1=s.charAt(i);
            char ch2=s.charAt(j);
            if(ch1=='a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u')
                len-=1;
             if(ch2=='a' || ch2=='e' || ch2=='i' || ch2=='o' || ch2=='u')
                len+=1;
             ans=Math.max(ans,len);    
           
        }
        
        return ans;
        
        
    }
}

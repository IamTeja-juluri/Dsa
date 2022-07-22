class Solution {
    public int longestSubstring(String s, int k) {
        
        int n=s.length();
        
        if(k>n || n==0)
            return 0;
        
        if(k<=1)
            return n;
        
        
        int[] count=new int[26];
        
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            count[ch-'a']+=1;
        }
            
         int l=0;
         char ch=s.charAt(l);
        
        while(l<n && count[ch-'a']>=k){
            l+=1;
            if(l<n)
            ch=s.charAt(l);
        }
        
        if(l>=n-1)
            return l;
        
        int lh=longestSubstring(s.substring(0,l),k);
        
        char ch1=s.charAt(l);
        while(l<n && count[ch1-'a']<k){
            l+=1;
            if(l<n)
            ch1=s.charAt(l);
        }
        
        int rh=(l<n)?longestSubstring(s.substring(l),k):0;
        return Math.max(lh,rh);
        
    }
}

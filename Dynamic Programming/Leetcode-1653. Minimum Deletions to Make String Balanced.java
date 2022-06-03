class Solution {
    public int minimumDeletions(String s) {
     
       int n=s.length(); 
       int[] cntA=new int[n];
        
       if(s.charAt(n-1)=='a')
           cntA[n-1]=1;
        
       for(int i=n-2;i>=0;i--)
           cntA[i]+=cntA[i+1]+(s.charAt(i) == 'a' ? 1 : 0);
        
        
       int ans=Integer.MAX_VALUE; 
       int bcnt=0;
        
       for(int i=0;i<n;i++){
           
           if(s.charAt(i)=='b'){
               int res=bcnt+cntA[i];
               ans=Math.min(res,ans);
               bcnt+=1;
           }
       } 
        
        ans=Math.min(bcnt,ans);
        
        return  ans == Integer.MAX_VALUE ? 0 : ans;
       
    }
}

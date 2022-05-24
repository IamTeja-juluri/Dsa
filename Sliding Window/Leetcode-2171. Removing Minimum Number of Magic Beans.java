class Solution {
    public long minimumRemoval(int[] beans) {
        
        
        int n=beans.length;
        if(n==1)
            return 0;
        
        long[] pref=new long[n];
        long[] suff=new long[n];
        
        
        Arrays.sort(beans);
        long sum=0;
        
        for(int i=0;i<n;i++){
            sum+=beans[i];
            pref[i]=sum;
        }
        
        sum=0;
        
        for(int i=n-1;i>=0;i--){
            sum+=beans[i];
            suff[i]=sum;
        }
        
        
        long minval=Long.MAX_VALUE;
        
        
        for(int i=0;i<n;i++){
        if(i==0)
             minval=Math.min(minval,suff[i+1]-(long)(n-1)*beans[i]);
        else if(i==n-1)
              minval=Math.min(minval,pref[i-1]);
        else
             minval=Math.min(minval,pref[i-1]+suff[i+1]-(long)(n-i-1)*beans[i]);   
    }
        
     return minval;   
    }
}

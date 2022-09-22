class Solution {
    public int getMaximumGenerated(int n) {
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int ans[]=new int[n+1];
        ans[0]=0;
        ans[1]=1;
        
        for(int i=0;i<n+1;i++){
            if(2 * i <= n && 2 * i >= 2)
                ans[2 * i]=ans[i];
            if((2 * i + 1 )<=n && (2 * i + 1)>=2)
                ans[(2 * i + 1)]=ans[i]+ans[i+1];
        }
        
        Arrays.sort(ans);
        return ans[n];
        
    }
}

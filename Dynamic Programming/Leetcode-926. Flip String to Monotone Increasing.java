class Solution {
    public int minFlipsMonoIncr(String s) {
        
        //for evry one  -we find number of ones on left and number of zeros on right
        //for every zero -we find number of ones on left and number of zeros on right
        
        int n=s.length();

        int[] suff=new int[n+1];
        
        int cnt1=0;
        int cnt0=0;

            
        for(int i=n-1;i>=0;i--){
            char ch=s.charAt(i);
            if(ch=='0')
                cnt0+=1;
           suff[i]=cnt0;
        }
        
        int ans=Integer.MAX_VALUE;
        
        for(int i=0;i<n;i++){
             char ch=s.charAt(i);
             ans=Math.min(ans,cnt1+suff[i+1]);
             if(ch=='1')
                cnt1+=1; 
        }
        
        return ans;
    }
}

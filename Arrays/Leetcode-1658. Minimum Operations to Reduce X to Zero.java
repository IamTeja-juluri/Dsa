class Solution {
    
    public int binarySearch(int low,int high,int key,int[] pref){
        
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(pref[mid]==key)
                return mid;
            else if(pref[mid]>key)
                  high=mid-1;
            else
                  low=mid+1;
        }
        
        return -1;   
    }
    
    
    
    public int minOperations(int[] nums, int x) {
        
        int n=nums.length;
        
        int[] pref=new int[n];
        int[] suff=new int[n];
        
        int sum=0;
        int op=Integer.MAX_VALUE-1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pref[i]=sum;
            if(pref[i]==x)
                op=i;
        }
        
        sum=0;
        
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suff[i]=sum;
        }
        
        
        int ans=Integer.MAX_VALUE;
        
        
        for(int i=n-1;i>=0;i--){
            
            int val=x-suff[i];
            
            if(val==0)
                ans=Math.min(ans,n-i);
            
            int idx=binarySearch(0,i-1,val,pref);
            
            if(idx!=-1){
                int len=idx+1+n-i;
                ans=Math.min(ans,len);
            }
            
        }
            
        ans=Math.min(ans,op+1);
        
        if(ans==Integer.MAX_VALUE)
            return -1;
        
       
        return ans;
    }
}

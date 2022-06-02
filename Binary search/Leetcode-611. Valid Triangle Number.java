class Solution {
    
    int binarySearch(int[] nums,int low,int high,int key){
        
        int idx=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=key)
                high=mid-1;
            else{
                low=mid+1;
                idx=mid;
            }
        }
        
        
        return idx;
    }
    
    
    public int triangleNumber(int[] nums) {
     
        int n=nums.length;
        
        Arrays.sort(nums);
        
        int cnt=0;
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<(n-1);j++){
                int sum=nums[i]+nums[j];
                int idx=binarySearch(nums,j+1,n-1,sum);
                if(idx!=-1)
                    cnt=cnt+idx-j;
            }
        }
         
        
        return cnt;
    }
}

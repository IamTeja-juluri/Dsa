//two ptr Efficient approach O(n^2)
class Solution {
    

    public int triangleNumber(int[] nums) {
     
        int n=nums.length;
        
        if(n<3)
            return 0;
        
        Arrays.sort(nums);
        
        int cnt=0;
        
        
        for(int i=2;i<n;i++){
            
            int left=0;
            int right=i-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    cnt=cnt+right-left;
                    right-=1;
                }
                else
                    left+=1;
            }
            
        }
        
        
        return cnt;
    }
}

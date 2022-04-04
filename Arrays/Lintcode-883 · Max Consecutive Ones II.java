public class Solution {
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    public int findMaxConsecutiveOnes(int[] nums) {
        // write your code here
       
       int n=nums.length;
       boolean flag=false;

       for(int i=0;i<n;i++){
           if(nums[i]==0){
               flag=true;
               break;
           }
       }

       if(flag==false)
       return n;
     
       int maxlength=0;

       for(int i=0;i<n;i++){
            
            int p1=i-1,p2=i+1;

            if(nums[i]==1)
            continue;
            

            while(p1>=0 && nums[p1]==1)
              p1-=1;

            while(p2<n && nums[p2]==1)
                p2+=1;

            maxlength=Math.max(maxlength,p2-p1-1);    

       }
        
      return maxlength;
    }
}

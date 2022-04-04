//soln1 (below soln2 is imp)
public class Solution {
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    public int maxSubArrayLen(int[] nums, int k) {
        // Write your code here
        
        Map<Integer,Integer> mp=new HashMap<Integer,Integer>();
    
        int curr_sum=0;
        int n=nums.length;
        int maxlength=0;

        for(int i=0;i<n;i++){
            curr_sum=curr_sum+nums[i];
            if(curr_sum==k)
            maxlength=i+1;
            else if(mp.get(curr_sum-k)!=null){
                maxlength=Math.max(maxlength,i-mp.get(curr_sum-k));
            }
            else if(mp.containsKey(curr_sum)==false)
            mp.put(curr_sum,i);
        }
      
       return maxlength;

    }
}


//soln2 imp
public class Solution {
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    public int maxSubArrayLen(int[] nums, int k) {
        // Write your code here
        
        Map<Integer,Integer> mp=new HashMap<Integer,Integer>();
    
        int curr_sum=0;
        int n=nums.length;
        int maxlength=0;
        mp.put(0,-1);
        for(int i=0;i<n;i++){
            curr_sum=curr_sum+nums[i];
             if(mp.get(curr_sum-k)!=null){
                maxlength=Math.max(maxlength,i-mp.get(curr_sum-k));
            }
            else if(mp.containsKey(curr_sum)==false)
            mp.put(curr_sum,i);
        }
      
       return maxlength;

    }
}

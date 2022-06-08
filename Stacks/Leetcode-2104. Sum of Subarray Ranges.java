class Solution {
    public long subArrayRanges(int[] nums) {
        
        //idea is to find how many times a particular number occurs in subarrays as a minimum
        //to find it we find next smaller element and previous smaller element idx
        //similarly we find how many times a particular number occurs in subarrays as a maximum
        ////to find it we find next greater element and previous greater element idx
        //den we subtract their sums individually
        Stack<Integer> st=new Stack<>();
       
        int n=nums.length;
        
        long[] nge=new long[n];
        long[] pge=new long[n];
        long[] nse=new long[n];
        long[] pse=new long[n];
        
        for(int i=0;i<n;i++){
            pse[i]=i;
            pge[i]=i;
            nse[i]=n-i-1;
            nge[i]=n-i-1;
        }
        
        // for next greater 
        for(int i=0;i<n;i++){
            while(st.isEmpty()==false && nums[i]>nums[st.peek()]){
                nge[st.peek()]=i-st.peek()-1;
                st.pop();
            }
            st.push(i);
        }
        
        
        st.clear();
         // for prev greater 
        for(int i=n-1;i>=0;i--){
            while(st.isEmpty()==false && nums[i]>=nums[st.peek()]){
                pge[st.peek()]=st.peek()-i-1;
                st.pop();
            }
            st.push(i);
        }
        
         st.clear();
        // for next smaller 
        for(int i=0;i<n;i++){
            while(st.isEmpty()==false && nums[i]<nums[st.peek()]){
                nse[st.peek()]=i-st.peek()-1;
                st.pop();
            }
            st.push(i);
        }
        
         st.clear();
         // for prev smaller 
        for(int i=n-1;i>=0;i--){
            while(st.isEmpty()==false && nums[i]<=nums[st.peek()]){
                pse[st.peek()]=st.peek()-i-1;
                st.pop();
            }
            st.push(i);
        }
        
        long sum1=0,sum2=0;
        
        for(int i=0;i<n;i++){
            sum1+=nums[i]*(pse[i]+1)*(nse[i]+1);
            sum2+=nums[i]*(pge[i]+1)*(nge[i]+1);
        }
        
        return sum2-sum1;
    }
}

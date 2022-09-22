//java
class Solution {
    public int[] dailyTemperatures(int[] nums) {
        
      
        Stack<Integer> st= new Stack<>();
        
        int n=nums.length;
        
        int[] nge=new int[n];
        
        for(int i=0;i<n;i++){
            if(st.isEmpty()==true)
                st.push(i);
            else{
                while( st.isEmpty()==false && nums[st.peek()]<nums[i]){
                    nge[st.peek()]=i-st.peek();
                    st.pop();
                }
                st.push(i);
            }
        }
        
        
        return nge;
    }
}
//cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
       
        stack<pair<int,int> > st;
        int n=nums.size();
        
        vector<int> nge(n,0);
        
        for(int i=0;i<n;i++){
            if(st.empty()==true)
                st.push({nums[i],i});
            else{
                while(!st.empty() and st.top().first<nums[i]){
                    nge[st.top().second]=i-st.top().second;
                    st.pop();
                }
                st.push({nums[i],i});
            }
        }
        
        
        return nge;
    }
};

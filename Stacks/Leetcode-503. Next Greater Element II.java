class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
       int n=nums.size();
        
       for(int i=0;i<n;i++)
           nums.push_back(nums[i]);
       
        int n1=2*n;
        stack<int> st;
        vector<int> res(n1,-1);
        
        for(int i=0;i<n1;i++){
            if(st.empty()==true){
                st.push(i);
                continue;
            }
            if(nums[i]<=nums[st.top()])
                st.push(i);
            else{
                while(!st.empty() && nums[i]>nums[st.top()]){
                    res[st.top()]=nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        while(n1> n){
            res.pop_back();
            n1-=1;
        }
        
        return res;
    }
};

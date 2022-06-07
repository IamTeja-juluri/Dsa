class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
        
        vector<int>nge(n,-1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums2[i]]=i;
        
        stack<int> st;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(nums2[i]<=nums2[st.top()])
                st.push(i);
            else{
                while(!st.empty() && nums2[i]>nums2[st.top()]){
                    nge[st.top()]=nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end())
                res.push_back(nge[mp[nums1[i]]]);
        }
        
        return res;
    }
};

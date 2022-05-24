class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        
        set<int> st;
        
        vector<int> ans;
        
       for(int i=0;i<nums1.size();i++){
           for(int j=0;j<nums2.size();j++){
               if(nums1[i]==nums2[j])
                   st.insert(nums1[i]);
           }
           for(int k=0;k<nums3.size();k++){
               if(nums1[i]==nums3[k])
                   st.insert(nums1[i]);
           }
       }
        
        for(int i=0;i<nums2.size();i++){
            for(int j=0;j<nums3.size();j++){
                if(nums2[i]==nums3[j])
                    st.insert(nums2[i]);
            }
        }
        
        
        for(auto x:st)
            ans.push_back(x);
        
        return ans;
    }
};

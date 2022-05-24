//java
class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        
        
        HashSet<Integer> st=new HashSet<>();
        
        List<Integer> ans=new ArrayList<>();
        
       for(int i=0;i<nums1.length;i++){
           for(int j=0;j<nums2.length;j++){
               if(nums1[i]==nums2[j])
                   st.add(nums1[i]);
           }
           for(int k=0;k<nums3.length;k++){
               if(nums1[i]==nums3[k])
                   st.add(nums1[i]);
           }
       }
        
        for(int i=0;i<nums2.length;i++){
            for(int j=0;j<nums3.length;j++){
                if(nums2[i]==nums3[j])
                    st.add(nums2[i]);
            }
        }
        
        
        for(Integer x:st)
           ans.add(x);
        
        return ans;
        
    }
}
//cpp
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

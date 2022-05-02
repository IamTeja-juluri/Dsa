class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        vector<int> nums1;
        vector<int> nums2;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            if((i%2)==0)
                nums1.push_back(nums[i]);
            else
                nums2.push_back(nums[i]);
        }
        
        sort(nums1.begin(),nums1.end()); //even array
        
        sort(nums2.begin(),nums2.end(),greater<int>());  // odd array
        
        int p1=0,p2=0;
        int n1=nums1.size();
        int n2=nums2.size();
        
        int i=0;
        
        while(p1<n1 && p2<n2){
            
            if((i%2)==0)
                res.push_back(nums1[p1++]);
            else
                res.push_back(nums2[p2++]);
            i+=1;
        }
        
        while(p1<n1)
             res.push_back(nums1[p1++]);
        
        while(p2<n2)
            res.push_back(nums2[p2++]);
        
        return res;
        
    }
};

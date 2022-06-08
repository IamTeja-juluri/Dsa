class Solution {
public:
    void reverse(vector<int>&nums,int l,int r){
        
        while(l<=r){
            swap(nums[l],nums[r]);
            l+=1;
            r-=1;
        }
        
    }
    
    void nextPermutation(vector<int>& nums) {
     
        int n=nums.size();
        int i=n-2;
        
        while(i>=0 && nums[i]>=nums[i+1])
            i-=1;
        
       if(i>=0){
          
           int j=n-1;
           while(j>i && nums[j]<=nums[i])
               j-=1;
           
           swap(nums[i],nums[j]);
           reverse(nums,i+1,n-1);
       }   
        else
            reverse(nums,0,n-1);
    
    }
};

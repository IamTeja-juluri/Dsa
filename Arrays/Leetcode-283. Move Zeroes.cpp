class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
        int n=nums.size();
        
        for(int j=0,i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j++]);
            }
        }
        
        
        
    }
};

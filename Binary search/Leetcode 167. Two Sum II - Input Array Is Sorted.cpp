class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        int n=nums.size();
        
        int low=0,high=n-1;
        vector<int> res;
        
        while(low<high){
            
            
            if(nums[low]+nums[high]==target){
                res.push_back(low+1);
                res.push_back(high+1);
                break;
            }
            else if(nums[low]+nums[high]>target){
                high-=1;
            }
            else{
                low+=1;
            }
            
        }
        
        
        return res;
    }
};
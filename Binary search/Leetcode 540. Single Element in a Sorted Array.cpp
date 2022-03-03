class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int  n=nums.size();
        
        int low=0,high=n-1;
        int ans;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if( mid-1>=0 && mid+1<n && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1] ){
                ans=nums[mid];
                break;
            }
            else if(mid-1>=0 && nums[mid]==nums[mid-1]){
                 
               if(mid%2==1){
                   low=mid+1;
               }
               else{
                   high=mid-2;
               }
                
            }
            else if(mid+1<n && nums[mid]==nums[mid+1]){
                if(mid%2==1){
                    high=mid-1;
                }
                else{
                    low=mid+2;
                }
                
            }
            else{
                ans=nums[mid];
                 break;
            }
            
        }
        
        return ans;
    }
};
class Solution {
public:
    
    bool binarySearch(vector<int>&nums,int m,int rsum){
        
        int sum=0;
        int n=nums.size();
        int count=1;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>rsum)
                return false;
            
            else if((sum+nums[i])>rsum){
                sum=nums[i];
                count++;
                if(count>m)
                    return false;
            }
            else
                sum=sum+nums[i];
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
     
        int n=nums.size();
        int sum=0;
        
        for(auto x:nums)
            sum+=x;
        
        int low=0,high=sum;
        int res=INT_MAX;
        
        while(low<=high){
         
        int mid=low+(high-low)/2;
            
         if(binarySearch(nums,m,mid)){
           int ans=mid;
           res=min(ans,res);
           high=mid-1;  
         }
         else
             low=mid+1;
            
        }
        return res;
    }
};

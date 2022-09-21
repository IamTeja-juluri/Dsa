//refer ayushi vermas video
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        int prod=1;
        int maxprod=INT_MIN;
        
        for(int i=0;i<n;i++){
            prod=prod*nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0)
                prod=1;
        }
        
        prod=1;
        
        for(int i=n-1;i>=0;i--){
            prod=prod*nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0)
                prod=1;
        }
        
        return  maxprod;
        
    }
};
//gfg
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int prod=1;
        int maxprod=INT_MIN;
        int min_eh=0;
        int max_eh=0;
        
        for(int i=0;i<n;i++){
            int temp=max({max_eh*nums[i],min_eh*nums[i],nums[i]});
            min_eh=min({min_eh*nums[i],nums[i],max_eh*nums[i]});
            max_eh=temp;
            maxprod=max(maxprod,max_eh);
        }
     
        return maxprod;
        
    }

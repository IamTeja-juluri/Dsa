//app1 with extra space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
            
          if(k>=n) 
            k=k%n;
        
        vector<int> res;
        
        int idx=n-k;
        
        while(idx<n){
            res.push_back(nums[idx]);
            idx+=1;
        }
        
        idx=0;
        int end=n-k;
        
        while(idx<end){
            res.push_back(nums[idx]);
            idx+=1;
        }
        
        int i=0;
        
        for(auto x:res){
            nums[i]=x;
            i+=1;
        }
        
    }
};
//app2 without extra space
//reversal technique
class Solution {
public:
    
    
    void reverse(vector<int>&nums,int l,int h){
        
        while(l<=h){
           swap(nums[l],nums[h]);
            l+=1;
            h-=1;
        }
        
        return;
    }
    
    
    
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
         
        k=k%n;
        
        reverse(nums,0,n-1); //reverse d whole array
        reverse(nums,0,k-1); //reverse first k numbers
        reverse(nums,k,n-1); //reverse last n-k elements
        
        
    }
};

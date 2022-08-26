//app1
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int> > res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            int reqsum=-nums[i];
            while(left<right){
                if(nums[left]+nums[right]>reqsum)
                    right-=1;
                else if(nums[left]+nums[right]<reqsum)
                    left+=1;
                else{
                    int secondvalue=nums[left];
                    int thirdvalue=nums[right];
                    res.push_back({nums[i],secondvalue,thirdvalue});
                    while(left<right and nums[left]==secondvalue)
                        left+=1;
                    while(right>left and nums[right]==thirdvalue)
                        right-=1;
                }
            }
            while(i+1<n and nums[i]==nums[i+1])
                i+=1;
        }
        
     
        return res;
    }
};
//app2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n=a.size();
        vector<vector<int> > res;
        
        if(n<3){
            return res;
        }
        
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-2;i++){
             
            int low=i+1;
            int high=n-1;
            
            
            if(i==0 || (i>0 && a[i]!=a[i-1]) ){
            while(low<high){
                
                if(a[low]+a[high]+a[i]==0){
                    
                    vector<int> v;
                    v.push_back(a[i]);
                    v.push_back(a[low]);
                    v.push_back(a[high]);
                    res.push_back(v);
                    
                    while(low<high && a[low]==a[low+1])   low+=1;
                    
                    while(low<high && a[low]==a[high-1]) high-=1;
                    
                    low+=1;
                    high-=1;
                    
                        
                }
                else if(a[low]+a[high]+a[i]>0){
                    high-=1;
                }
                else{
                    low+=1;
                }
                
            }
         }
            
      }
        
     
        return res;
        
    }
};

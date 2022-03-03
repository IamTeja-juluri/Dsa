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
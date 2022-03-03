class Solution {
public:
    
    vector<vector<int>>res;
       
    void backTrack(vector<int>&ans,int idx,int s,int n,int k){
        
        if(s==n){
            
            if(k==0){
                res.push_back(ans);
            }
            
            return ; 
        }
        
        if(k<=0 || idx>9) return;
        
        
        for(int i=idx;i<=9;i++){
            
            if( (s+i)<=n ){

                ans.push_back(i);
                backTrack(ans,i+1,s+i,n,k-1);
                ans.pop_back();
                
            }
            
            
        }
          
        return ;
        
    }
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
     
        vector<int> ans;
        backTrack(ans,1,0,n,k);
        return res;
        
    }
};

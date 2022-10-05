class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
      
       
        long long count[5*10000+1]={0};
        
        for( auto x:roads){
            count[x[0]]+=1;
            count[x[1]]+=1;
        }
        
        long long ans=0;
        
        sort(count,count+n);
        
        for(int i=0;i<n;i++){
            ans=ans+count[i]*(i+1);
        }
        
        return ans;
    }
};

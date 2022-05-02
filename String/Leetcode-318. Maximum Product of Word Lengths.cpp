class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        
        int n=words.size();
        
        vector<int> mask(n+1,0);
        
        for(int i=0;i<words.size();i++){
            
            int m=0;
            for(auto x:words[i])
                m=m|(1<<(x-'a'));
            
            mask[i]=m;
        }
    
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int n1=words[i].size();
            
            for(int j=i+1;j<n;j++){
                
                int n2=words[j].size();
               
                if(!(mask[i] & mask[j]) )
                    ans=max(ans,n1*n2);
                
            }
        }
        
        return ans;
        
    }
};

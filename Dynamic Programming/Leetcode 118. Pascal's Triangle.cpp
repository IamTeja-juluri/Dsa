class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int> >pascals;
       
        
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    v.push_back(1);
                }
                else{
                    v.push_back(pascals[i-1][j]+pascals[i-1][j-1]);
                }
            }
            
            pascals.push_back(v);
            
        }
        
        return pascals;
        
    }
};
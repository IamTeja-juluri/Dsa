class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        if(n*m!=r*c)
            return mat;
        
        
        vector<vector<int> > matrix(r,vector<int>(c,0));
        int p=0,q=0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[p][q]=mat[i][j];
                q+=1;
                if(q==c){
                    p+=1;
                    q=0;
                }
            }
        }
         
        
        return matrix;
    }
};

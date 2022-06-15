class Solution {
public:
    
    vector<vector<int> > flipMatrix(vector<vector<int> > mat,int x,int y){
        
        int n=mat.size();
        int m=mat[0].size();
        
        mat[x][y]^=1;
        
        if(x-1>=0)
            mat[x-1][y]^=1;
        
         if(x+1<n)
            mat[x+1][y]^=1;
        
         if(y-1>=0)
            mat[x][y-1]^=1;
        
        if(y+1<m)
            mat[x][y+1]^=1;
        
       return mat;
        
    }
    
    
    int minFlips(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int> > res(n,vector<int>(m,0));
        
        set<vector<vector<int> > > visited;
        
        queue<vector<vector<int> > > q;
        int steps=0;
        q.push(mat);
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                
                auto v=q.front();
                q.pop();
                
                if(v==res)
                    return steps;
                
                if(visited.find(v)!=visited.end())
                continue;
                
                visited.insert(v);
                
                for(int j=0;j<v.size();j++){
                    for(int k=0;k<v[0].size();k++){
                        vector<vector<int> > r=flipMatrix(v,j,k);
                        q.push(r);
                    }
                } 
                
            }
            
            steps+=1;
        }
        
        
        return -1;   
    }
};

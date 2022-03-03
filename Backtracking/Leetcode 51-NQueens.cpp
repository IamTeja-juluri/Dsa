class Solution {
public:
    
    
    bool isValid(int l,int r,int n,vector<string>&v){
        
        //Along col
        int i=0,j=0;
        
        while(i<n){
            if(v[i][r]=='Q'){
                return false;
            }
            i+=1;
        }
        
        // Along row
        
        while(j<n){
            if(v[l][j]=='Q'){
                return false;
            }
            j+=1;
            
        }
        
        //ALong topleft diognal
        
        i=l,j=r;
        
        
        while(i>=0 && j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i-=1;
            j-=1;
        }
        
        // Along top right diognal
        
        i=l,j=r;
        
        while(i>=0 && j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i-=1;
            j+=1;
        }
        
        return true;
        
    }
    
    void Nqueens(vector<vector<string> > &res,vector<string>&v,int i,int n){
        
        
        if(i==n){
            res.push_back(v);
            return ;
        }
        
        for(int j=0;j<n;j++){
            
            if(isValid(i,j,n,v)){
                
                v[i][j]='Q';
                Nqueens(res,v,i+1,n);
                v[i][j]='.';
            }
            
        }
        
        
       return; 
        
    }
    
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>res;
        
        string s;
        
        for(int i=0;i<n;i++){
            s=s+'.';
        }
        
        vector<string>v(n,s);

        
        Nqueens(res,v,0,n);
        
        return res;
        
    }
};

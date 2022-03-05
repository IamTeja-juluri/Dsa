class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int x, int y, int newColor,int color){
        
        
        int n=image.size();
        int m=image[0].size();
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && image[newx][newy]==color){
                
                  image[newx][newy]=newColor;
                dfs(image,newx,newy,newColor,color);
            }
        }
        
        return;
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc]==newColor)
            return image;
        
        int n=image.size();
        int m=image[0].size();
        
        int color=image[sr][sc];
        
        image[sr][sc]=newColor;
        dfs(image,sr,sc,newColor,color);
        
        return image;
        
        
    }
};

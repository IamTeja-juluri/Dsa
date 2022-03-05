class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        queue<pair<int,int> > q;
        q.push({start[0],start[1]});

         int n=maze.size();
        int m=maze[0].size();
       

        vector<vector<bool> > visited(n,vector<bool> (m,false)); 
        
        visited[start[0]][start[1]]=true;
       
        while(!q.empty()){
             
             int x=q.front().first;
             int y=q.front().second;


             q.pop();

             for(int i=0;i<4;i++){
                
                int newx=x;
                int newy=y;

                while(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==0  ){
                       
                       newx+=dx[i];
                       newy+=dy[i];   

                }
                
                newx-=dx[i];
                newy-=dy[i];

               if(newx==destination[0] && newy==destination[1]){
                   return true;
               }
                     
               if(visited[newx][newy]==false){
                   visited[newx][newy]=true;
                   q.push({newx,newy});
               }
               

             }

         

        }
 
    return false;

    }
};

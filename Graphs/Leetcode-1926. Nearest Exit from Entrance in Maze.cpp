class Solution {
    public:
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {        
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int n=maze.size();
        int m=maze[0].size();
    
        while(!q.empty())
        {
            int n1=q.size();
            for(int i=0;i<n1;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]=='.')
                    {
                        if(newx==0 || newy==0 || newx==n-1|| newy==m-1)
                            return steps;
                        q.push({newx,newy});
                        maze[newx][newy]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

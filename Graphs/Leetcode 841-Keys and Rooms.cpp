class Solution {
public:
    
    
    void dfs(int node,vector<bool>&visited,vector<vector<int>>&rooms){
        
        visited[node]=true;
        
        for(auto nbr:rooms[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,rooms);
            }
        }    
        
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();

        
        vector<bool>visited(n,false);
        
        dfs(0,visited,rooms);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        
        return true;
        
    }
};

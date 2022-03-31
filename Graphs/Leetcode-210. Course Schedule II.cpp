class Solution {
public:
 
    vector<int>gr[2005];
    vector<bool>visited,stack;
    vector<int>ans;
    
   
    // void topodfs(int node){
    //     visited[node]=true;
    //     for(auto nbr:gr[node]){
    //         if(!visited[nbr])
    //             topodfs(nbr);
    //     }
    //     ans.push_back(node);
    //     return;
    // }
    
    bool containsCycleHelper(int node){
        visited[node]=true;
        stack[node]=true;
        for(auto nbr:gr[node]){
            if(!visited[nbr]){
                bool nbrfound=containsCycleHelper(nbr);
                if(nbrfound)
                    return true;
            }
            else if(stack[nbr]==true)
                return true;
        }
        stack[node]=false;
        return false;
    }
    
    bool containsCycle(int n){
        
        visited.resize(n,false);
        stack.resize(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool cyclefound=containsCycleHelper(i);
                if(cyclefound)
                   return true;
            }
        }
        
        return false;
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        
        for(auto x:preq){
            gr[x[1]].push_back(x[0]);
        }
        
        if(containsCycle(n))
            return ans;
        
//         visited.resize(n,false);
        
//         for(int i=0;i<n;i++){
//             if(!visited[i])
//                 topodfs(i);
//         }     
        
//         reverse(ans.begin(),ans.end());
        
        //topobfs-Kahns algorithm
        queue<int>q;
        vector<int>indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(auto nbr:gr[i])
                indegree[nbr]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:gr[node]){
                indegree[nbr]-=1;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        return ans;
    }
};

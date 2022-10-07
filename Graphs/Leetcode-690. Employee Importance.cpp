/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int getImportance(vector<Employee*> emp, int id) {
            
        int imp=0;
        unordered_map<int,pair<int,vector<int> > > mp;
        queue<int> q;
        q.push(id);
       
        unordered_map<int,bool> visited;
        visited[id]=true;
      
        for(auto x:emp)
            mp[x->id]={x->importance,x->subordinates};
        
        imp=mp[id].first;
        
        while(!q.empty()){
            int src=q.front();
            q.pop();
            for(auto nbr:mp[src].second){
                if(!visited[nbr]){
                    imp=imp+mp[nbr].first;
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }      
        }
      
        return imp;
    }
};

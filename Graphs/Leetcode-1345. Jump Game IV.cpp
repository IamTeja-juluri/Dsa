//standard template 1
class Solution {
public:
    int minJumps(vector<int>& nums) {
     
        int n=nums.size();
        map<int,vector<int> >mp;
        vector<bool> visited(n,false);
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        
        queue<int>q;
        
        int steps=0;
        q.push(0);
        
        while(!q.empty()){
          
            int qsize=q.size();
            
            for(int i=1;i<=qsize;i++){
                
                int idx=q.front();
                 q.pop();
                
                if(idx==n-1)
                return steps;
            
                 
                if(visited[idx])
                continue;
            
                visited[idx]=true;
            
                int op1=idx+1;
                int op2=idx-1;
                
                if(op1<n)
                    q.push(op1);
                
                if(op2>=0)
                    q.push(op2);
                
                vector<int> v=mp[nums[idx]];
                
                for(auto x:v){
                    if(x==idx)
                        continue;
                    q.push(x);
                }
                mp.erase(nums[idx]);
            }
            
            steps+=1;  
        }
        
        return steps;
    }
};
//standard template 2
class Solution {
public:
    int minJumps(vector<int>& nums) {
     
        int n=nums.size();
        map<int,vector<int> >mp;
        vector<bool> visited(n,false);
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        
        queue<int>q;
        
        int steps=0;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
          
            int qsize=q.size();
            
            for(int i=1;i<=qsize;i++){
                
                int idx=q.front();
                 q.pop();
                
                if(idx==n-1)
                return steps;
            
                int op1=idx+1;
                int op2=idx-1;
                
                if(op1<n && !visited[op1]){
                    visited[op1]=true;
                    q.push(op1);
                }
                
                if(op2>=0 && !visited[op2]){
                    visited[op2]=true;
                    q.push(op2);
                }
                
                vector<int> v=mp[nums[idx]];
                
                for(auto x:v){
                    if(x==idx || visited[x])
                        continue;
                    q.push(x);
                    visited[x]=true;
                }
                mp.erase(nums[idx]);
            }
            
            steps+=1;  
        }
        
        return steps;
    }
};

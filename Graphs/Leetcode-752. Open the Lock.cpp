//Bfs
class Solution {
public:
   
    int openLock(vector<string>& deadends, string target) {
     
        
        queue<string> q;
        unordered_set<string> mp(deadends.begin(),deadends.end());
        
        unordered_map<string,bool>visited;
        
       string start="0000";
        if(mp.find(start)!=mp.end())
            return -1;
        
        if(target==start)
            return 0;

        q.push(start);
        visited[start]=true;
        int steps=0;
        
        while(!q.empty()){
            
            steps+=1;
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                
                string curr=q.front();
                q.pop();
                
               for(int j=0;j<4;j++){
                   
                 string temp1=curr;
                 temp1[j]=(curr[j]-'0'+1)%10 + '0';
                   
                 if(target==temp1)
                     return steps;
                  
                 if(!visited[temp1]){
                     visited[temp1]=true;
                     if(mp.find(temp1)==mp.end())
                     q.push(temp1);
                  }
                   
                 temp1[j]=(curr[j]-'0'-1+10)%10 +'0';
                   
                 if(target==temp1)
                     return steps;
                  
                 if(!visited[temp1]){
                     visited[temp1]=true;
                     if(mp.find(temp1)==mp.end())
                     q.push(temp1);
                  } 
                   
                   
               } 
                
                
          }
                            
       }
        
        
        return -1;
        
    }
};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        set<string> s;
        
        for(auto x:bank)
            s.insert(x);
        
        
        if(s.find(end)==s.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        int level=0;
        
        string changeto="ACGT";
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                
                string temp=q.front();
                q.pop();
                
                for(int j=0;j<temp.size();j++){
                    
                   
                    
                    for(int k=0;k<changeto.size();k++){
                       
                        
                        if(temp[j]==changeto[k])
                            continue;
                        
                         char tempvar=temp[j];
                         
                        temp[j]=changeto[k];
                        
                        if(temp==end)
                            return level+1;
                        
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                        
                        temp[j]=tempvar;
                        
                    }
                    
                    
                }
                
                
            }
            
            level+=1;
        
        }
        
        return -1;
        
    }
};

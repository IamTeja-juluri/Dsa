class Solution {
public:
    
    unordered_map<string,int> mp;
    
    int ladderLength(string bw, string ew, vector<string>& wordList) {
        
        set<string>s;
        
        for(auto x:wordList)
            s.insert(x);
    
        if(s.find(ew)==s.end())
            return 0;
        
        queue<string>q;
        
        q.push(bw);
        int level=1;
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                
                string temp=q.front();
                q.pop();
                
                for(int j=0;j<temp.size();j++){
                    
                    for(char ch='a';ch<='z';ch++){
                        
                        if(ch==temp[j])
                            continue;
                        
                        char tempvar=temp[j];
                        
                        temp[j]=ch;
                        if(temp==ew)
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
        
        return 0;
    }
};

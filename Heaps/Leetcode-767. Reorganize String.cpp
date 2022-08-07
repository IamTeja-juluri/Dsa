class Solution {
public:
    
    string reorganizeString(string s) {
        
        int n=s.size();
        int count[26]={0};
        
        for(int i=0;i<n;i++)
            count[s[i]-'a']+=1;
        
        priority_queue<pair<int,char> >pq;
        
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']!=0)
                pq.push({count[ch-'a'],ch});
        }
        
        string ans="1";
      
        while(!pq.empty()){
            
            pair<int,char> p=pq.top();
            pq.pop();
            
            int idx=ans.size();
            
            if(p.second!=ans[idx-1]){
               ans=ans+p.second; 
               if(p.first>1) 
               pq.push({p.first-1,p.second});
            }
            
            else if(!pq.empty()){
                    
                    pair<int,char> p1=pq.top();
                    pq.pop();
                    ans=ans+p1.second;
                    if(p1.first>1)
                    pq.push({p1.first-1,p1.second});
                    pq.push(p);
                }
            else
                return "";
        }
        
        
     
        return ans.substr(1);
    }
};

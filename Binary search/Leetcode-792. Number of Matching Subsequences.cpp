//Binary search
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.size();
        int m=words.size();
        
       unordered_map<char,vector<int>>mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]].push_back(i);
        
        int ans=0;
       
        
        
        for(auto x:words){
            
            bool found=true;
            int previdx=-1;
            
            for(int i=0;x[i]!='\0';i++){
                  
                
                if(mp.find(x[i])==mp.end()){
                    found=false;
                    break;
                }
                else{
                    
                    auto pos=upper_bound(mp[x[i]].begin(),mp[x[i]].end(),previdx);
                    if(pos==mp[x[i]].end()){
                        found=false;
                        break;
                    }
                    else
                        previdx=*pos;
                }
            }
            
            if(found)
                ans+=1;
        }
        
        return ans;
    }
};
//linear search
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.size();
        int m=words.size();
        
       unordered_map<char,vector<int>>mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]].push_back(i);
        
        int ans=0;
       
        
        
        for(auto x:words){
            
            bool found=true;
            int previdx=-1;
            
            for(int i=0;x[i]!='\0';i++){
                
                if(mp.find(x[i])==mp.end()){
                    found=false;
                    break;
                }
                else{
                    int temp=previdx;
                    for(auto idx:mp[x[i]]){
                        if(idx>previdx){
                            previdx=idx;
                            break;
                        }
                    }
                    if(temp==previdx)
                        found=false;
                }
                
            }
            
            
            if(found)
                ans+=1;
        }
        
        return ans;
    }
};

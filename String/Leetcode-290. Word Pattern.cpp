class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string,string> mp1,mp2;
        
        queue<string> q;
        
        int i=0;
        
        while(i<s.size()){
            
            string word="";
            
            while(i<s.size() && s[i]!=' '){
                word=word+s[i];
                i++;
            }
            
            q.push(word);
            
            while(i<s.size() && s[i]==' ')
                i+=1;
            
        }
        
        if(q.size()!=pattern.size())
            return false;
        
        for(auto x:pattern){
            
            string curr=q.front();
            q.pop();
            
            string temp="";
            temp=temp+x;
            
            if(mp1.find(temp)!=mp1.end()){
                if(mp1[temp]!=curr)
                    return false;
            }
            
            else if(mp1.find(temp)==mp1.end()){
                if(mp2.find(curr)!=mp2.end())
                    return false;
            }
            
            mp1[temp]=curr;
            mp2[curr]=temp;
        }
        
        return true;
        
    }
};

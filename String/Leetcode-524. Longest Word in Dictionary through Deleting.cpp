class Solution {
public:
    
    
    bool isSubsequence(string &s1,string &s2){
        
        int n=s1.size();
        int m=s2.size();
        int j=0;
        
        for(int i=0;j<n && i<m;i++){
            
            if(s1[j]==s2[i])
                j+=1;
        }
        
        return j==n;
    }
    
    
    string findLongestWord(string s, vector<string>& dict) {
     
        set<string> st(dict.begin(),dict.end());
        string ans="";
        
        for(auto x:st){
            
            int n1=x.size();
            if(isSubsequence(x,s)){
                if(ans.size()<x.size())
                    ans=x;
            }
            
        }
        
        
        
        return ans;
    }
};

//Not optimal but gives ac
class Solution {
public:
    
    vector<string> v;
    unordered_set<string> st;
    
    void permutations(string &s,int l,int r){
        
        if(l==r){
            v.push_back(s);
            return;
        }
        
        for(int i=l;i<=r;i++){
            
            swap(s[i],s[l]);
            permutations(s,l+1,r);
            swap(s[i],s[l]);
        }
        
        return;
    }
    
    
    void generateSubsets(string &s,string &ans,int idx,int n){
        
        if(idx==n){
            st.insert(ans);
            return;
        }
        
        ans.push_back(s[idx]);
        generateSubsets(s,ans,idx+1,n);
        ans.pop_back();
        generateSubsets(s,ans,idx+1,n);
        
    }
    
    
    int numTilePossibilities(string s) {
        
        int n=s.size();
        
        permutations(s,0,n-1);
        
        for(auto x:v){
            int n1=x.size();
            string temp="";
            generateSubsets(x,temp,0,n1);
        }
        
        int cnt=st.size();
        return cnt-1;
    }
};
2)class Solution {
public:
    
    vector<string> v;
    unordered_set<string> st;
    
    void permutations(string &s,int l,int r){
        
        if(l==r){
            v.push_back(s);
            return;
        }
        
        for(int i=l;i<=r;i++){
            
            swap(s[i],s[l]);
            permutations(s,l+1,r);
            swap(s[i],s[l]);
        }
        
        return;
    }
    
    
    void generateSubsets(string &s,int n){
        
        
        for(int i=0;i<(1<<n);i++){
            string temp="";
            for(int j=0;j<n ;j++){
                if(i&(1<<j))
                    temp.push_back(s[j]);
            }
                st.insert(temp);
        }
    
        
    }
    
    
    int numTilePossibilities(string s) {
        
        int n=s.size();
        
        permutations(s,0,n-1);
        
        for(auto x:v){
            int n1=x.size();
            generateSubsets(x,n1);
        }
        
        int cnt=st.size();
        return cnt-1;
    }
};

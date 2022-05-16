
1)class Solution {
public:
    
      unordered_set<string> st;
      int ans;
   void solve(int idx, string s)
   {
       
       if(idx==s.size()){
           int size=st.size();
           ans=max(ans,size);
           return;
       }
      
    string x= "";
    for(int i=idx; i<s.length(); i++)
    {
        x += s[i];
        if(st.find(x) == st.end())
        {
            st.insert(x);
            solve(i+1,s);
            st.erase(x);
        }
    }
}

int maxUniqueSplit(string str) {
    
  
    ans= 0;
    
    solve(0,str);
    
    return ans;
}
};
2)class Solution {
public:
    
      unordered_set<string> st;
      int ans;
   void solve(int idx, string s,int c)
   {
       
       if(idx==s.size()){
           ans=max(ans,c);
           return;
       }
      
   
    for(int i=idx; i<s.length(); i++)
    {
        string x=s.substr(idx,i-idx+1);
        if(st.find(x) == st.end())
        {
            st.insert(x);
            solve(i+1,s,c+1);
            st.erase(x);
        }
    }
}

int maxUniqueSplit(string str) {
    
  
    ans= 0;
    
    solve(0,str,0);
    
    return ans;
}
};

class Solution {
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

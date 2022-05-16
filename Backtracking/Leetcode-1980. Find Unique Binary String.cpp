class Solution {
public:
    
    unordered_set<string> st;
    string ans="";
    
    
    void backtrack(string &s,int idx){
        
        if(idx==s.size()){
            if(st.find(s)==st.end())
                ans=s;
            return;
        }
        
        s[idx]=s[idx]^1; //toggles
        backtrack(s,idx+1);
        s[idx]=s[idx]^0; //toggles 
        backtrack(s,idx+1);
        
    }
    
    
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        for(auto x:nums)
            st.insert(x);
        
        for(auto x:nums){
           
            backtrack(x,0);
            int size=ans.size();
            if(size!=0)
                break;
        }
        
        
        return ans;
    }
};

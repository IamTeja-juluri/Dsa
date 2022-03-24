class Solution {
public:
    string decodeString(string s) {
        
        stack<char>st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]!=']')
                st.push(s[i]);
            
            else{
                
                string subs="";
                
                while(!st.empty() && st.top()!='['){
                    subs=st.top()+subs;
                    st.pop();
                }
                st.pop();
                
                string nums="";
                
                while(!st.empty() && isdigit(st.top())){
                    nums=st.top()+nums;
                    st.pop();
                }
                
                int k;
                
                if(nums.size()==0)
                    k=1;
                else
                   k=stoi(nums);
                
                while(k--){
                    
                    for(int j=0;j<subs.size();j++){
                        st.push(subs[j]);
                    }
                    
                }
                
            }
            
        }
        
        
        string res="";
        
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        
        return res;
        
    }
};

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto x:s){
            if(x==')'){
                if(st.empty() || st.top()!='(')
                    return false;
                st.pop();
            }
            else if(x==']'){
                 if(st.empty() || st.top()!='[')
                     return false;
                st.pop();
            }
            else if(x=='}'){
                if(st.empty() || st.top()!='{')
                    return false;
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        
        return st.size()==0;
    }
};

//app2
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
              return false;
    
            else
            {
                char x;
                switch(s[i])
                {
                    case ')':
                       x=st.top() ;
                        st.pop();
                        if(x!='(')
                            return false;
                        break;
                     case '}':
                       x=st.top() ;
                        st.pop();
                        if(x!='{')
                            return false;
                        break;
                     case ']':
                       x=st.top() ;
                        st.pop();
                        if(x!='[')
                            return false;
                        break;       
                }
                
            }
         
         }
        if(st.empty())
            return true;
        return false;
        
    }
};

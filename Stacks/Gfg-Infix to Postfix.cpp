    int prec(char ch){
        if(ch=='^')
        return 3;
        else if(ch=='*' or ch=='/')
        return 2;
        else if(ch=='+' or ch=='-')
        return 1;
        return -1;
    }
    
    string infixToPostfix(string s) {
        
        int n=s.size();
        
        string pfx="";
        stack<char>st;
        
        
        for(int i=0;i<n;i++){
            
            if( (s[i]>=97 and s[i]<=122) or (s[i]>=65 and s[i]<=92) )
                pfx+=s[i];
            else if( s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() and st.top()!='('){
                    pfx=pfx+st.top();
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }    
            else{
                while(!st.empty() and prec(s[i])<=prec(st.top())){
                    pfx=pfx+st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
               
        }  
        
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            pfx+=ch;
        }
        
     return pfx;    
    
    }

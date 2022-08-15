int evaluatePostfix(string s)
    {
        int n=s.size();
        stack<int>st;
        
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                st.push(s[i]-'0');
            }
            else{
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int ans=0;
                if(s[i]=='+')
                ans=first+second;
                else if(s[i]=='-')
                ans=second-first;
                else if(s[i]=='*')
                ans=first*second;
                else
                ans=second/first;
                st.push(ans);
            }
        }
        
        int ans=0;
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        
        return ans;
    }

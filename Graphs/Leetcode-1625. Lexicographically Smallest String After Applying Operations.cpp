class Solution {
public:
    
    string rotate(string &s,int b){
        
//         string temp="";
//         int n=s.size(); gives tle
        
//         for(int i=0;i<n;i++)
//             temp=temp+"0";
        
//         for(int i=0;i<n;i++)
//             temp[(i+b)%n]=s[i];
        
//         return temp;
         
        int n = s.size();
        reverse(s.begin() + n - b, s.end());
        reverse(s.begin(), s.begin() + n - b);
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    
    string findallstrings(string &s,int a,int b){
        
        int n=s.size();
        string temp=s;
        
        for(int i=1;i<n;i+=2)
            temp[i]=(s[i]-'0'+a)%10 + '0';
       
        return temp;
    }
    
    string findLexSmallestString(string s, int a, int b) {
        
        queue<string> q;
        q.push(s);
        set<string> st;
        st.insert(s);
        while(!q.empty()){
                string curr=q.front();
                q.pop();
                string s1=(findallstrings(curr,a,b));
                string s2=(rotate(curr,b));
                if(st.find(s1)==st.end()){
                    st.insert(s1);
                    q.push(s1);
                   }
                 if(st.find(s2)==st.end()){
                    st.insert(s2);
                    q.push(s2);
                   }          
         }    
        
        auto it=st.begin();
        return *(it);
    }
};

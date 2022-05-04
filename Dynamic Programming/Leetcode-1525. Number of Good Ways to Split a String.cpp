class Solution {
public:
    int numSplits(string s) {
        
        int n=s.size();
        vector<char> prf,suff;
        set<char> st;
        
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            prf.push_back(st.size());
        }
        
        st.clear();
        
         for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            suff.push_back(st.size());
        }
        
        reverse(suff.begin(),suff.end());
        
        int cnt=0;
        
        for(int i=1;i<n;i++){
            if(prf[i-1]==suff[i])
                cnt+=1;
        }
        
        return cnt;
        
    }
};

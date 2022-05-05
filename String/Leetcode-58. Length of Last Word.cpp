class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.size();
        
        reverse(s.begin(),s.end());
        
        int i=0;
        
        while(i<n && s[i]==' ')
            i+=1;
        
        int cnt=0;
        
        while(i<n && s[i]!=' '){
            i+=1;
            cnt+=1;
        }
        
        return cnt;
    }
};

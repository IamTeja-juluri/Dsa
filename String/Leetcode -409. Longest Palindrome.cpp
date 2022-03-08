class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> mp;
        
        int evenlen=0;
        int n=s.size();
        
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        int count=0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if((it->second)%2==1){
                count++;
            }
            evenlen+=it->second;
        }
       
        if(!count) return evenlen;
        
        return evenlen-(count-1);
    }
};

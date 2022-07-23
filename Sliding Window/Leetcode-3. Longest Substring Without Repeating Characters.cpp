class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        unordered_map<int,int> mp;
        
        int j=0;
        int ans=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            mp[s[i]]+=1;
            if(mp[s[i]]>1){
                while(mp[s[i]]>1){
                    mp[s[j]]--;
                    j+=1;
                }
            }
            ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};

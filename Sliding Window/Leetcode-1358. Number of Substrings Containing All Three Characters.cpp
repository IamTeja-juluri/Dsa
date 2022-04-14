class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int count=0;
        unordered_map<char,int> mp;
        int j=0;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]+=1;
            while(mp.size()==3){
                count=count+s.size()-i;
                mp[s[j]]-=1;
                if(mp[s[j]]==0)
                    mp.erase(s[j]);
                j+=1;
            }
        }
        
        return count;
    }
};

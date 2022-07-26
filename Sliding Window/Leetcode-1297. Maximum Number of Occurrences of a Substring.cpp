class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        unordered_map<char,int> mp;
        unordered_map<string,int> freq;
        int j=0;
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
            while(mp.size()>maxLetters || i-j+1>minSize){
               mp[s[j]]-=1;
               if(mp[s[j]]==0)
                   mp.erase(s[j]);
                j+=1;
            }
            if(i-j+1>=minSize and i-j+1<=maxSize){
                string temp=s.substr(j,i-j+1);
                freq[temp]+=1;
            }
        }
        for(auto it:freq)
            ans=max(ans,it.second);
        
       return ans;
    }
};

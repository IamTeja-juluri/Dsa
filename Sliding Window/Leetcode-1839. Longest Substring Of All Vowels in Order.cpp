class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
         int ans = 0;
        
        for(int i=0,j=0,cnt=0; j<word.size(); j++) {
            if(word[j] != 'a') continue;
            
            for(i=j + 1; i<word.size() && word[i - 1] <= word[i]; i++) cnt += word[i - 1] < word[i];
            if(cnt == 4) ans = max(ans, i - j);
            j = i-1, cnt = 0;
        }
        return ans;
    }
};
//app2
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
         int ans = 0;
        unordered_map<char,int>mp;
        mp[word[0]]+=1;
        
        int j=0;
        for(int i=1;i<word.size();i++){
            if(word[i]<word[i-1]){
                j=i;
                mp.clear();
            }
            mp[word[i]]+=1;
            if(mp.size()==5)
                ans=max(ans,i-j+1);
            
        }
        return ans;
    }
};

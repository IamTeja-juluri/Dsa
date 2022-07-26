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

class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
       int ans=0;
       
       unordered_map<char,int>mp;
       int n=s.size();
       int j=0;

       for(int i=0;i<n;i++){
          mp[s[i]]+=1;
          while(mp.size()>2){
              mp[s[j]]-=1;
              if(mp[s[j]]==0)
                mp.erase(s[j]);
                j+=1;
          }
           ans=max(ans,i-j+1);
       }
        

       return ans;
    }
};

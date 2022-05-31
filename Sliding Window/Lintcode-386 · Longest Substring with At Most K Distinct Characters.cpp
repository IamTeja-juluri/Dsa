class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        
        if(s.size()==0 || k==0)
        return 0;

        int j=0;
        
        unordered_map<char,int>mp;

        int ans=0;

        for(int i=0;i<s.size();i++){

          mp[s[i]]+=1;
        
          while(mp.size() > k && j<=i){
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

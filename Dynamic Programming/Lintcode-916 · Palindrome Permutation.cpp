// Given a string, determine if a permutation of the string could form a palindrome.
class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        int n=s.size();
        unordered_map<char,int> mp;

        for(auto x:s)
            mp[x]++;

        int ans=0;

        for(auto it=mp.begin();it!=mp.end();it++){
            int x=it->first;
            int y=mp[x];
            if(y%2==1){
             ans+=1;
             if(ans>1) 
               return false;
            }
        }    
        return true;
    }
};

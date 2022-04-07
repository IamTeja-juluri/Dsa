//Gives Tle
class Solution {
public:
    
    bool isPalindrome(string s){
        
        int l=0,r=s.size()-1;
        
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
     
        vector<vector<int>> res;
        
        unordered_map<string,int> mp;
        
        
        for(int i=0;i<words.size();i++){
            string reversedword=words[i];
            reverse(reversedword.begin(),reversedword.end());
            mp[reversedword]=i;
        }
        
        
        int i=0;
        
        for(auto x:words){
                for(int j=0;j<x.size();j++){
                    string left=x.substr(0,j);
                    string right=x.substr(j);
                    if(mp.find(left)!=mp.end() && mp[left]!=i && isPalindrome(right)){
                        res.push_back({i,mp[left]});
                        if(left.empty())
                            res.push_back({mp[left],i});
                    }
                     if(mp.find(right)!=mp.end() && mp[right]!=i && isPalindrome(left))
                         res.push_back({mp[right],i});
                }
            i+=1;
        }        
        return res;
    }
};

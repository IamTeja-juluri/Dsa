class Solution {
public:
    
    static bool compare(const string s1,const string s2){
        
        return s1+s2>s2+s1;
    }
    
    
    string largestNumber(vector<int>& nums) {
        
       vector<string> v;
        
        for(auto x:nums)
            v.push_back(to_string(x));
        
        sort(v.begin(),v.end(),compare);
        
        string ans="";
        
        for(auto x:v)
            ans=ans+x;
        
        if(ans[0]=='0')
            return "0";
        
        return ans;
    }
};

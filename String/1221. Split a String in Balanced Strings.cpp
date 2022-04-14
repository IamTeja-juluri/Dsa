class Solution {
public:
    int balancedStringSplit(string s) {
        
        int count=0;
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')
                count+=1;
            else
                count-=1;
              if(count==0)
                    ans+=1;
        }
        
        return ans;
    }
};

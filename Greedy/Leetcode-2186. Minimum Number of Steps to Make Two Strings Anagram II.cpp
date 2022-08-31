class Solution {
public:
    int minSteps(string s, string t) {
        
        int count1[26]={0};
        int count2[26]={0};
        
        for(int i=0;i<s.size();i++)
            count1[s[i]-'a']+=1;
        
        for(int i=0;i<t.size();i++)
            count2[t[i]-'a']+=1;
        
        int op=0;
        
        for(int i=0;i<26;i++){
            if(count1[i]==count2[i])
                continue;
            op+=abs(count1[i]-count2[i]);
        }
        
  
        return op;
    }
};

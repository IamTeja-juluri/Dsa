class Solution {
public:
    int minSteps(string s, string t) {
     
        int count1[26]={0};
        int count2[26]={0};
        
        for(auto x:s)
            count1[x-'a']+=1;
        
         for(auto x:t)
            count2[x-'a']+=1;
        
        
        int mincount=0;
        
        for(int i=0;i<26;i++){
            
            if(count1[i]>count2[i])
                mincount+=count1[i]-count2[i];
    
        }
        
        return mincount;
        
    }
};

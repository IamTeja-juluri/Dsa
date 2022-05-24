class Solution {
public:
    
    bool compareStrings(vector<int>&a1,vector<int>&a2){
        
        for(int i=0;i<26;i++){
            if(a1[i]!=a2[i])
                return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        
        vector<int>a1(26,0),a2(26,0);
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1>n2)
            return false;
        
        for(auto x:s1)
            a1[x-'a']+=1;
        
        for(int i=0;i<n1;i++)
            a2[s2[i]-'a']+=1;
        
         if(compareStrings(a1,a2))
                return true;
    
        
        for(int j=0,i=n1;i<n2;i++,j++){
            a2[s2[j]-'a']-=1;
            a2[s2[i]-'a']+=1;
            if(compareStrings(a1,a2))
                return true;
        }
        
        return false;
    }
};

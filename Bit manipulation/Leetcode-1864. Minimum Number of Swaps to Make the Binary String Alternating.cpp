class Solution {
public:
    
    
    int countswaps(string &s,char ch){
        
        int swaps=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]!=ch)
                swaps+=1;
            if(ch=='0')
                ch='1';
            else
                ch='0';
        }
        
        return swaps/2;
    }
    
    
    
    int minSwaps(string s) {
        
        int cnt0=0,cnt1=0;
        
        for(int i=0;i<s.size();i++){
            cnt0=cnt0+(s[i]=='0');
            cnt1=cnt1+(s[i]=='1');
        }
        
        int diff=abs(cnt0-cnt1);
        
        if(diff>1)
            return -1;
        
        if(cnt0>cnt1)
            return countswaps(s,'0');
        else if(cnt0<cnt1)
            return countswaps(s,'1');
        else
            return min(countswaps(s,'0'),countswaps(s,'1'));
        
    }
};

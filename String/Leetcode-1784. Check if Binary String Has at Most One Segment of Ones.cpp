class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int n=s.size();
        
        if( (n==1 || n==2) && s[0]=='1')
            return true;
        
        int count=0;
        int ans=0;
        
        int i=0;
        
        while(i<n){
            
            
            while(i<n && s[i]=='1'){
                count++;
                i++;
            }
            
            while(i<n && s[i]=='0'){
                i++;
            }
            
            if(count){
                ans+=1;
                if(ans>1)
                    return false;
            }
            
            count=0;
        }
        
        return true;
    }
};

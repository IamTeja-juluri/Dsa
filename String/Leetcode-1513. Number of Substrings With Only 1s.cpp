class Solution {
public:
    int numSub(string s) {
        
        int i=0;
        int n=s.size();
        long res=0;
        int mod=1e9+7;
        
        while(i<n){
            
            if(s[i]=='0'){
                i+=1;
                continue;
            }
            
            bool flag=false;
            long cnt=1;
            int j=i+1;
            while(j<n && s[i]=='1' && s[i]==s[j]){
                flag=true;
                j+=1;
                cnt+=1;
            }
            
            long val=(cnt*(cnt+1))/2;
            res+=val;
            res%=mod;
            if(flag==false)
                i+=1;
            else
                i=j;
            
        }
        
        return res;
    }
};

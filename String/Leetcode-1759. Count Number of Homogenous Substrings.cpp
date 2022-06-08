class Solution {
public:
    int countHomogenous(string s) {
        
        int n=s.size();
        long  res=0;
        int mod=1e9+7;
        
        int i=0;
        
        while(i<n){
            long  cnt=1;
            bool flag=false;
            int j=i+1;
            while(j<n && s[i]==s[j]){
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

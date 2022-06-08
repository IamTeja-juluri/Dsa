//java
class Solution {
    public int countHomogenous(String s) {
      
        int n=s.length();
        long res=0;
        int mod=(int)1e9+7;
        
        int i=0;
        
        while(i<n){
            long cnt=1;
            boolean flag=false;
            int j=i+1;
            char ch1=s.charAt(i);
            char ch2='a'; //just to initialise sommething
            if(j<n)
            ch2=s.charAt(j);
            while(j<n && ch1==ch2){
                flag=true;
                j+=1;
                if(j<n)
                    ch2=s.charAt(j);
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
        
        return (int)res;
      
    }
}
//cpp
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

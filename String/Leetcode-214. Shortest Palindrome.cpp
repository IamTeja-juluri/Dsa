//kmp application
//append reverse string towrds righht
//compute lps array
//remove len of lps[n-1] from reverse string
//add the remaining part to i/p string
class Solution {
public:
    
    int compute(string s){
        
        int n=s.size();
        vector<int>lps_arr(n,0);
        int i=1,j=0;
        
        while(i<n){
            
            if(i<n && s[i]==s[j]){
                lps_arr[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j==0){
                     i+=1;
                    lps_arr[i]=0;
                }
                else
                    j=lps_arr[j-1];
            }
            
        }
        
        return lps_arr[n-1];
        
    }
    
    
    
    string shortestPalindrome(string s) {
        
        int n=s.size();
        
        if(n==0)
            return "";
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        string temp=s+'#'+rev;
        int len=compute(temp);
        
        string x=rev.substr(0,n-len)+s;
        
        return x;
    }
};

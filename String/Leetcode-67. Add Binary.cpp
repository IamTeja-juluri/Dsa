class Solution {
public:
    string addBinary(string a, string b) {
        
        int n=a.size();
        int m=b.size();
        
        if(n>m){
            int k=n-m;
            while(k--){
                b='0'+b;
            }
        }
        else if(m>n){
            int k=m-n;
            while(k--){
                a='0'+a;
            }
        }
        
        n=a.size();
        int carry=0;
        string ans="";
        
        for(int i=n-1;i>=0;i--){
            
           if(carry==0){
                if(a[i]=='0' && a[i]==b[i]){
                    ans=ans+"0";
                    carry=0;
                }
                else if(a[i]=='1' && a[i]==b[i]){
                    ans+="0";
                    carry=1;
                }
                else if(a[i]!=b[i]){
                    ans+="1";
                    carry=0;
                }
            }
            else{
                if(a[i]=='0' && a[i]==b[i]){
                    ans=ans+"1";
                    carry=0;
                }
                else if(a[i]=='1' && a[i]==b[i]){
                    carry=1;
                    ans=ans+"1";
                }    
                else if(a[i]!=b[i]){
                    ans=ans+"0";
                    carry=1;
                 }    
            }
            
        }
    
        if(carry)
            ans=ans+'1';
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

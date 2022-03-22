class Solution {
public:
    string convertToBase7(int num) {
        
        if(num==0)
            return "0";
        
        int temp=abs(num);
        string ans="";
        
        while(temp){
            int r=temp%7;
            ans=ans+to_string(r);
            temp/=7;
        }
        
        reverse(ans.begin(),ans.end());
        
        if(num<0){
            ans='-'+ans;
        }
            
       return ans;
            
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
     
        int ans=1;
        int dup=0,not_dup=9;
        
        for(int i=1;i<=n;i++){
            
            dup=dup*10+not_dup*(i-1);
            not_dup=pow(10,i)-pow(10,i-1)-dup;
            
            ans=ans+not_dup;
        }
        
        return ans;
    }
};

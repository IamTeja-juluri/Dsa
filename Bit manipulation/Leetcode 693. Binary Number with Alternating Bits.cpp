class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        if(n==1) return true;
                
        
        while(n>1){
            
            int i=n&1;
            int j=(n>>1)&1;
            
            if(i==j){
                return false;
            }
            
            n=n>>1;
        }
        
        return true;
    }
};

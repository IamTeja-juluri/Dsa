class Solution {
public:
    double myPow(double x, int n) {

        
        double res=1;
        long long num=n;
        
        if(num<0)
            num=-num;
        
        while(num){
            
            if(num&1)
                res=res*x;
            
               x=x*x;
               num/=2;
        }
        
        if(n<0){
            res=(1.0)/res;
        }
        
        return res;
        
        
    }
};

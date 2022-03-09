class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1)
           return true;
        
        for(long long i=2;i*i<=num;i++){
            if(num/(i*i)==1 && num%(i*i)==0)
                return true;
        }
        
        return false;
    }
};

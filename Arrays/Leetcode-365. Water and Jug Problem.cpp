class Solution {
public:
    int gcd(int a,int b){
        
        if(a==0)
            return b;
        
        return gcd(b%a,a);
    
    }
    
    bool canMeasureWater(int jug1C, int jug2C, int targetC) {
        
        if((jug1C+jug2C)<targetC)
           return false;
        
        if(targetC%(gcd(jug1C,jug2C))!=0)
            return false;
            
        return true;
    }
};

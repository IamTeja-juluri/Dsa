class Solution {
public:
    int arrangeCoins(int n) {
        
        int num=1;
        int count=0;
        
        while(1){
            if(num<=n){
                n=n-num;
                count+=1;
                num+=1;
            }
            else
                break;
        }
        
        return count;
    }
};

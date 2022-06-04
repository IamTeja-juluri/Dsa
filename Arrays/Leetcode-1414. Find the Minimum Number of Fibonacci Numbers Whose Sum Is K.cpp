class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        if(k<=2)
            return 1;
        
        vector<int>fib;
        
        fib.push_back(0);
        fib.push_back(1);
        
        int idx=0;
        
        for(int i=2;i<=k+1;i++){
            fib.push_back(fib[i-1]+fib[i-2]);
            if(fib[i]<=k)
                idx=i;
            else
                break;
        }
        
        int cnt=0;
        
        while(idx>=1){
            if(k-fib[idx]>=0){
                k-=fib[idx];
                cnt+=1;
            }
            idx-=1;
        }
        
            return cnt;
    }
};

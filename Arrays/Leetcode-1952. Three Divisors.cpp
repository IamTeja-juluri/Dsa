class Solution {
public:
    bool isThree(int n) {
        
        int ans=0;
        
        for(int i=1;i*i<=n;i++){
             if(n%i==0 && n!=i*i)
                 ans+=2;
             else if(n%i==0)
                 ans+=1;
        }
        
        
        return ans==3;
    }
};

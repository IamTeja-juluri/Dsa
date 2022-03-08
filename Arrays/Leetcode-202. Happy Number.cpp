class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int,int> mp;
        
        while(n!=1){
            
            if(mp.find(n)!=mp.end()) return false;
            
            mp[n]+=1;
            
            int temp=n;
            int sum=0;
            
            while(temp){
                sum=sum+(temp%10)*(temp%10);
                temp/=10;
            }
            n=sum;
            
        }
        
        return true;
    }
};

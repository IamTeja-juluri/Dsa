class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> res;
        
        for(int i=left;i<=right;i++){
            
            int num=i;
            int flag=0;
            while(num){
                int r=num%10;
                if(r==0 || (i%r)!=0){
                    flag=1;
                    break;
                }
                num/=10;
            }
            
            if(flag==0)
                res.push_back(i);
        
        }
        
        return res;
        
    }
};

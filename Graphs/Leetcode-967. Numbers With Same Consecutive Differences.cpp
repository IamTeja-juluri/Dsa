class Solution {
public:
    
    vector<int>res;
    
    void dfs(int num,int n,int k){
        
        if(n==0){
            res.push_back(num);
            return;
        }
        
      for(int i=0;i<=9;i++){
         int diff=abs((num%10)-i);
            if(diff==k)
               dfs(num*10+i,n-1,k); 
        }
       
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++)
            dfs(i,n-1,k);
        
        return res;
    }
};

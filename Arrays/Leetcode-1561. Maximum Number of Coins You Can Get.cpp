//soln1
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n=piles.size();
        int ans=0;
        
        sort(piles.begin(),piles.end(),greater<int>());
        
        for(int i=0;i<n-n/3;i++){
            if(i%2)
                ans+=piles[i];
        }
        
        return ans;
    }
};
//soln2-using heap
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n=piles.size();
        int ans=0;
        
        priority_queue<int> maxhp;
           
        for(auto x:piles)
            maxhp.push(x);
        
        int i=0;
          
       while(!maxhp.empty() && i<(2*n)/3){
           
           maxhp.pop();
           ans+=maxhp.top();
           maxhp.pop();
           i+=2;
       }
        
        
        return ans;
    }
};

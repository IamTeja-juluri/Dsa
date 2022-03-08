class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minval=INT_MAX;
        int profit=0;
        
        for(auto x:prices){
            if(minval>x)
                minval=x;
            else
                profit=max(profit,x-minval);
        }
        
        return profit;
        
    }
};

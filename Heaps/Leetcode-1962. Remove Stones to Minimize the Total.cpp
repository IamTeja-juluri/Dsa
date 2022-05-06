class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<double> pq;
        
        for(auto x:piles)
            pq.push(x);
        
        
        while(!pq.empty() && k--){
          
            double x=pq.top();
            pq.pop();
            
            x=x-floor(x/2);
            pq.push(x);
            
        }
        
       double s=0;
        
        while(!pq.empty()){
            s+=pq.top();
            pq.pop();
        }
        return s;
    }
};

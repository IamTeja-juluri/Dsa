class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int> > pq;
        
        for(auto x:nums)
            pq.push(x);
        
    long long ans=1;
    long long mod=1e9+7;    
        
        while(k){
            
            int x=pq.top();
            pq.pop();
            x=x+1;
            pq.push(x);
            k--;
        }
        
        while(!pq.empty()){
            ans=(ans*pq.top())%(mod);
            pq.pop();
        }
            
        return ans;
        
    }
};

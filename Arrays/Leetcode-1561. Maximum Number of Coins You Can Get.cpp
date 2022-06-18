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

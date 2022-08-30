class Solution {
public:
    
    vector<long long > dp;
    
    int findFloor(int idx,vector<vector<int> > &rides){
        
       int low=idx,high=rides.size()-1,ans=rides.size();
        
        while(low<=high){
            int mid=(high+low)/2;
            if(rides[mid][0]>=rides[idx][1]){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
        
    }
    
    long long helper(int idx,vector<vector<int> > &rides){
        
        if(idx>=rides.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int next_idx=findFloor(idx,rides);
        int profit=rides[idx][1]+rides[idx][2]-rides[idx][0];
        
       return dp[idx]=max(profit+helper(next_idx,rides),helper(idx+1,rides));
        
    }
    
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        sort(rides.begin(),rides.end());
        int size=rides.size();
        dp.resize(size+1,-1);
        
        return helper(0,rides);
    }
};

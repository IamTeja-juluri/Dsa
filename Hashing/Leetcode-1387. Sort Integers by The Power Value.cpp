class Solution {
public:
    
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        
        if(p1.second==p2.second)
            return p1.first<p2.first;
        
        return p1.second<p2.second;
    }
    
    unordered_map<int,int>dp;
    
    int findans(int num){
        
        if(num==1)
            return 0;
        
        if(dp.find(num)!=dp.end())
            return dp[num];
        
        if(num%2)
            return dp[num]=1+findans(num*3+1);
        
        return dp[num]=1+findans(num/2);
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int> > res;
        
       for(int i=lo;i<=hi;i++)
           res.push_back({i,findans(i)});
       
        sort(res.begin(),res.end(),compare);
      
        return res[k-1].first;
    }
};

class Solution {
public:
    
    vector<int> dp;
    
    bool linearsearch(vector<int>&days,int day){
        
        for(int i=0;i<days.size();i++){
            if(day==days[i])
                return true;
        }
        
        return false;
    }
    
    int findout(vector<int>&days,vector<int>&costs,int day){
        
        
        if(day>days[days.size()-1])
            return 0;
        
        if(dp[day]!=-1)
            return dp[day];
        
        if(linearsearch(days,day)==false)
            return  dp[day]=findout(days,costs,day+1);
        
        
        int a=costs[0]+findout(days,costs,day+1);
        int b=costs[1]+findout(days,costs,day+7);
        int c=costs[2]+findout(days,costs,day+30);
        
        return dp[day]=min({a,b,c});
    }
    
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        dp.resize(days[days.size()-1]+1,-1);
        int ans=findout(days,costs,days[0]);
        return ans;
    }
    
};

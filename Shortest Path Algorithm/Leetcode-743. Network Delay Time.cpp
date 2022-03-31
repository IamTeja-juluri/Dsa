//Dijkshtra
//works for both directed and undirected  graphs with non negve edges
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int> >l[n+1];
        
        for(auto x:times){
            int f=x[0];
            int s=x[1];
            int w=x[2];
            l[f].push_back({s,w});
        }
        
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        set<pair<int,int>>s;
        s.insert({0,k});
        int ans=0;
        
        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int dist=it->first;
            s.erase(it);
            for(auto nbrPair:l[node]){
                int nbr=nbrPair.first;
                int nbrwt=nbrPair.second;
                if(dist+nbrwt<time[nbr]){
                    auto f=s.find({time[nbr],nbr});
                    if(f!=s.end())
                        s.erase(f);       
                    time[nbr]=dist+nbrwt;
                    s.insert({time[nbr],nbr});
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX)
                return -1;
            ans=max(ans,time[i]);
        }
        
        return ans;
    }
};

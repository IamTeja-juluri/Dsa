class Solution {
public:
    
    struct comp{
        
        bool operator()(pair<int,string> const &p1,pair<int,string> const &p2){
         
            if(p1.first!=p2.first)
                return p1.first<p2.first;
            else
                return p1.second>p2.second;
            
        }
        
        
    };
    
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> res;
        
        map<string,int>mp;
        
        for(auto x:words)
            mp[x]+=1;
        
        priority_queue<pair<int,string>,vector<pair<int,string> >,comp > pq;
        
        for(auto it:mp)
            pq.push({it.second,it.first});
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return res;
    }
};

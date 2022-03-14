class Solution {
public:

    string frequencySort(string s) {
        
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(auto x:s)
            mp[x]+=1;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push({it->second,it->first});
        
        
        string ans="";
        
        while(pq.size()>0){
          
           int x=pq.top().first;
           char y=pq.top().second;
            
           while(x--)
               ans.push_back(y); //append takes more time than push_back so use pushback
            
            pq.pop();
        }
        
        return ans;

        
    }
};

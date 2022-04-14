class comparator{
  public:
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
         if(p1.first==p2.first)
            return p1.second<p2.second;
        
        return p1.first>p2.first;
    }
    
};
class Solution {
public:
   
//     static bool compare(const pair<int,int> &p1,const pair<int,int> &p2){
//          if(p1.first==p2.first)
//             return p1.second<p2.second;
        
//         return p1.first>p2.first;
       
//     }
   
    
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> res;
        unordered_map<int,int> mp;
        
        priority_queue<pair<int,int>, vector<pair<int,int> > ,comparator> pq;
    
        for(auto x:nums)
            mp[x]+=1;
        
        int n=mp.size();

       for(auto it:mp)
           pq.push({it.second,it.first});
      
        while(!pq.empty()){
            int x=pq.top().second;
            int freq=pq.top().first;
            while(freq--)
                res.push_back(x);
            pq.pop();
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int>>& points, int k) {
     
        vector<vector<int> > res;
        
        priority_queue<   pair<long double,vector<int> >,vector<pair<long double,vector<int> > >, greater<pair<long double,vector<int > > > > pq;
        
        for(auto x:points){ 
            int f=x[0];
            int s=x[1];
            long double d=sqrt(f*f + s*s );
            vector<int> v;
            v.push_back(f);
            v.push_back(s);
            pq.push({d,v});
        }
        
        while(!pq.empty() && k!=0){
            
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
    
        
        return res;
    }
};

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int>>& points, int k) {
     
        vector<vector<int> > res;
        
        priority_queue<   pair<long double,vector<int> >,vector<pair<long double,vector<int> > >, greater<pair<long double,vector<int > > > > pq;
        
        //O(n)
        for(auto x:points){ 
            int f=x[0];
            int s=x[1];
            long double d=sqrt(f*f + s*s );
            vector<int> v;
            v.push_back(f);
            v.push_back(s);
            pq.push({d,v});
        }
        
        //O(klogN)
        while(!pq.empty() && k!=0){
            
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
    
        //Overall Tc=O(N+klogN)
        
        return res;
    }
};

//Optimised soln 

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int>>& points, int k) {
     
        vector<vector<int> > res;
        
        // priority_queue<   pair<long double,vector<int> >,vector<pair<long double,vector<int> > >, greater<pair<long double,vector<int > > > > pq;
        priority_queue< pair<long double,vector<int> > > pq;
        
        //O(k)
        for(int i=0;i<k && i<points.size();i++){
            int f=points[i][0];
            int s=points[i][1];
            vector<int> v;
            v.push_back(f);
            v.push_back(s);
            long double d=sqrt(f*f + s*s);
            pq.push({d,v});
        }
        
        //O((n-k)(logk+logk))
        
        for(int i=k;i<points.size();i++){
            int f=points[i][0];
            int s=points[i][1];
            long double d=sqrt(f*f + s*s);
            vector<int> v;
            v.push_back(f);
            v.push_back(s);
            if(pq.top().first>d){
                pq.pop();
                pq.push({d,v});
            }
        }
        
        //O(kLogK)
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        //Overall  Tc:O(k+(n-k)(logk+logk)+kLogK)
        return res;
    }
};

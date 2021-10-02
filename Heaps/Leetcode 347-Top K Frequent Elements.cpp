class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
   int n=a.size();
    map<int ,int > mp1;
    for(int i=0;i<n;i++)
    mp1[a[i]]+=1;
     multimap<int ,int ,greater<int> > mp2;
     for(auto it=mp1.begin();it!=mp1.end();it++)
     {
         mp2.insert(make_pair(it->second,it->first));
     }
     vector< int> rs;
     int i=0;
     for(auto it=mp2.begin();i<k;it++,i++)
     {
         rs.push_back(it->second);
     }
         return rs;
    }
};

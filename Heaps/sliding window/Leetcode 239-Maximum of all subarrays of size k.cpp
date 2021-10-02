class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
      int n=a.size();
      priority_queue<pair<int,int> > h;
      vector<int> res;
      for(int i=0;i<k;i++)
      {
         h.push(make_pair(a[i],i));
      }
      res.push_back(h.top().first);
      for(int i=1,j=k;j<n;j++,i++)
      {
           h.push(make_pair(a[j],j));
          while( h.top().second<i )
          h.pop();
           res.push_back(h.top().first); 
      }
        return res;
    }
};

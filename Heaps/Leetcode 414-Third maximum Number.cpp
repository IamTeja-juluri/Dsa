class Solution {
public:
    int thirdMax(vector<int>& v) {
        int n=v.size();
        make_heap(v.begin(),v.end());
        if(n<3)
            return v[0];
        set<int> s;
         int res=v[0];
        while(n--)
        {
            pop_heap(v.begin(),v.end());
           int k=v[n];
            v.pop_back();
            s.insert(k);
            if(s.size()==3)
                break;
        }
       
        if(s.size()==3)
        {
            auto it=s.begin();
            res=*it;
        }
        return res;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        make_heap(v.begin(),v.end());
        while((v.size())>1)
        {

            int f=v[0];
            pop_heap(v.begin(),v.end());
            v.pop_back();
            
             int s=v[0];
            pop_heap(v.begin(),v.end());
            v.pop_back();
            
            int res=f-s;
            if(res!=0)
            {
                v.push_back(res);
                push_heap(v.begin(),v.end());
            }
        }
        if(v.size())
            return v[0];
        
        return 0;
        
    }
};

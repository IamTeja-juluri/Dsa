class Solution {
public:
    
    
    
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
      vector<int> odd,even;
        
        for(auto x:nums)
            if((x%2)==0)
                even.push_back(x);
            else
                odd.push_back(x);
        
        int n=even.size();
        int m=odd.size();
        int p1=0,p2=0;
        int i=0;
        
        vector<int> res;
        while(p1<n && p2<m){
            
            if((i%2)==0)
                res.push_back(even[p1++]);
            else
                res.push_back(odd[p2++]);
            i+=1;
        }
        
        while(p1<n)
            res.push_back(even[p1++]);
        
        while(p2<m)
            res.push_back(odd[p2++]);        
        
        return res;
    }
};

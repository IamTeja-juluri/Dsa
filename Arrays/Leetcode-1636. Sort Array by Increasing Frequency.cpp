class Solution {
public:
    
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        
         if(p1.second==p2.second)
            return p1.first>p2.first;
        
          return p1.second<p2.second; 
    }
    
    
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> res;
        map<int,int> mp;
        
        for(auto x:nums)
            mp[x]+=1;
        
        int n=mp.size();
        
        pair<int,int> p[n];
        int i=0;
        
        for(auto it:mp)
            p[i++]={it.first,it.second};
        
        sort(p,p+n,compare);
        
        for(auto x:p){
            int num=x.first;
            int freq=x.second;
            while(freq--)
                res.push_back(num);
        }
        
        
        return res;
    }
};

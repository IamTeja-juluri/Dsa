//using multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int j=0;
        
        int n=nums.size();
        int ans=0;
       multiset<int> m;
        
        
        for(int i=0;i<n;i++){
            m.insert(nums[i]);
            auto it1=m.begin();
            auto it2=--m.end();
            while(*it2-*it1>limit){
                m.erase(m.find(nums[j]));
                it1=m.begin();
                it2=--m.end();
                j+=1;
            }
           ans=max(ans,i-j+1);
        }
        
        
        return ans;
    }
};

//using heap
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int j=0;
        
       int n=nums.size();
       int ans=0;
       multiset<int>m;
        
       priority_queue<pair<int,int> > maxhp;
       priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > minhp;
        
    
        for(int i=0;i<n;i++){
            
            maxhp.push({nums[i],i});
            minhp.push({nums[i],i});
            
            while(maxhp.top().first-minhp.top().first>limit){
                
                int pos=min(maxhp.top().second,minhp.top().second);
                if(maxhp.top().second==pos)
                    maxhp.pop();
                else
                    minhp.pop();
            
                while(maxhp.top().second<pos)
                    maxhp.pop();
                while(minhp.top().second<pos)
                    minhp.pop();
                j=pos+1;
            }
            
            ans=max(ans,i-j+1);
            
        }
        
        return ans;
    }
};

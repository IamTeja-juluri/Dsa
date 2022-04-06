class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
     
        int n=arr.size();
        
        priority_queue<pair<int,int>  > pq;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        for(auto it:mp){
            int f=it.first;
            int s=it.second;
            pq.push({s,f});
        }
        
        int size=0;
        int half=n/2;
        
        while(n>half){
            n=n-pq.top().first;
            pq.pop();
            size+=1;
        }
        
        return size;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int> > res;
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k>0){
            res.push_back({pq.top().second,pq.top().first});
            pq.pop();
            k-=1;
        }
        sort(res.begin(),res.end());
        vector<int> ans;
        for(auto it:res){
            ans.push_back(it.second);
        }
        return ans;
    }
};

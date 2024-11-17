class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(auto i:nums){
            pq.push(i);
        }
        vector<int> res;
        while(!pq.empty()){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            res.push_back(second);
            res.push_back(first);
        }
        return res;
    }
};

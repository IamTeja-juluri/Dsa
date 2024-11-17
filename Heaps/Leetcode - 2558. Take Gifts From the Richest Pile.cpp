class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        long long ans = 0;

        priority_queue<int> pq;

        for(auto i: gifts){
            pq.push(i);
        }

        for(int i=0;i<k;i++){
            auto  it = pq.top();
            pq.pop();
            pq.push(sqrt(it));
        }

        while(!pq.empty()){
            auto val =  pq.top();
            ans = ans + val;
            pq.pop();
        }

        return ans;
    }
};

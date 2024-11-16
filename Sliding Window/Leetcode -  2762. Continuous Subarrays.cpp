class Solution {
public:
    long long continuousSubarrays(vector<int>& v) {
        
    long long mini = INT_MAX;
    long long maxi = INT_MIN;

    long long count = 0;

    priority_queue<pair<int,int> > maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // 5 3 7 4 8 

    for(int j=0,i=0;i<v.size();i++){

        minHeap.push({v[i],i});
        maxHeap.push({v[i],i});

        while(abs(minHeap.top().first - maxHeap.top().first)>2){
           ++j;
           while(!maxHeap.empty() && maxHeap.top().second<j){
             maxHeap.pop();
           }
           while(!minHeap.empty() && minHeap.top().second<j){
             minHeap.pop();
           }
         
        }
        count = count + (i-j+1);

    }

    return count;
    }
};



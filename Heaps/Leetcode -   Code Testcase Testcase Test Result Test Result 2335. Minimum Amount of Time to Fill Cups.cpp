class Solution {
public:
    int fillCups(vector<int>& amount) {
        
       priority_queue<int> maxHeap;
        
      for(int i=0;i<amount.size();i++){
        maxHeap.push(amount[i]);
      }

    int count=0;

      while(maxHeap.top()!=0){

        int first = maxHeap.top();
        maxHeap.pop();
        first-=1;

        int second = maxHeap.top();
        maxHeap.pop();
        second-=1;

        maxHeap.push(first);
        maxHeap.push(second);

        count+=1;

      }

      return count;

    }
};

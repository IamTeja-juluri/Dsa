// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {


//         sort(nums.begin(),nums.end());
         
//         priority_queue<int,vector<int>,greater<int> > pq;

//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0)
//              continue;
//             pq.push(nums[i]);            
//         }

//         if(!pq.size()){
//             return 0;
//         }

//         int k = 0;
         
//         while(!pq.empty()){
//             int firstTop = pq.top();
//             pq.pop();
//             while(!pq.empty()){
//                 int secondTop = pq.top();
//                 pq.pop();
//                 if(secondTop-firstTop>0){
//                     pq.push(secondTop-firstTop);
//                     break;
//                 }
//             }
//             k+=1;
//          }

//          return k-1;

//     }
// };

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int operations = 0;
        int lastVal = 0;  // Keep track of the last processed distinct value

        // Iterate through the sorted array
        for (int i = 0; i < n; i++) {
            // Skip zero values
            if (nums[i] == 0) {
                continue;
            }

            // If the current value is greater than the last processed value, 
            // this means we need an operation for this new distinct value.
            if (nums[i] > lastVal) {
                operations++;
                lastVal = nums[i];
            }
        }

        return operations;
    }
};

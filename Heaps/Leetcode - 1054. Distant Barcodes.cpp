// class Solution {
// public:
//     vector<int> rearrangeBarcodes(vector<int>& barcodes) {

//         if(barcodes.size()<=1)
//             return barcodes;

//         priority_queue<pair<int,int> > maxheap;
//         priority_queue<pair<int,int> > minheap;

//         vector<int> res;
//         map<int,int, greater<int> > mp;

//         for(auto i : barcodes){
//             mp[i]+=1;
//         }

//         int i = 1;

//         for(auto it=mp.begin();it!=mp.end();it++){
//             if(i%2 == 1){
//                 maxheap.push({it->second,it->first});
//             }else{
//                 minheap.push({it->second,it->first});
//             }
//             i+=1;
//         }

//         i=1;

//         while(maxheap.size()>0){
//             if(i%2 == 1){
//                 res.push_back(maxheap.top().second);
//                 pair<int,int> p = maxheap.top();
//                 p.first = p.first-1;
//                 maxheap.pop();
//                 if(p.first!=0)
//                     maxheap.push(p);
//             }else{
//                 res.push_back(minheap.top().second);
//                 pair<int,int> p = minheap.top();
//                 p.first = p.first-1;
//                 minheap.pop();
//                 if(p.first!=0)
//                     minheap.push(p);
//             }
//             i+=1;
//         }

        

//         return res;
       
//     }
// };

// // 5 -> 4
// // 4 -> 3
// // 3 -> 2

// //  5 4 5 4 5 4 3 5 3



class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() <= 1)
            return barcodes;

        // Frequency map to count occurrences of each barcode
        map<int, int> mp;
        for (auto i : barcodes) {
            mp[i] += 1;
        }

        // Max heap to store (frequency, barcode)
        priority_queue<pair<int, int>> maxheap;
        for (auto& entry : mp) {
            maxheap.push({entry.second, entry.first});
        }

        // Result array to store rearranged barcodes
        vector<int> res(barcodes.size());
        int index = 0;

        // Process the max heap and alternate placement in result
        while (!maxheap.empty()) {
            auto [freq, barcode] = maxheap.top();
            maxheap.pop();

            // Place the barcode in the result at the current index
            for (int i = 0; i < freq; i++) {
                res[index] = barcode;
                index += 2;  // Alternate between even and odd indices
                if (index >= res.size()) {
                    index = 1;  // Once we reach the end of even indices, start filling odd indices
                }
            }
        }

        return res;
    }
};

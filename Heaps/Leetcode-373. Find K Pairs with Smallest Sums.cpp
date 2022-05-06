class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> res;
        
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        priority_queue<pair<int,pair<int,int> > > pq;
        for(int i=0;i<min(n1,k);i++){
            for(int j=0;j<min(n2,k);j++){
                int size=pq.size();
                if(size<k)
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                else if(pq.top().first>(nums1[i]+nums2[j])){
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else
                    break;
            }
        }
        
        while(!pq.empty() && k--){
            pair<int,pair<int,int> > p=pq.top();
            pq.pop();
            res.push_back({p.second.first,p.second.second});
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> ans;
        ans.push_back(first);
        int n=encoded.size();
        
        for(int i=1;i<=n;i++){
            ans.push_back(ans[i-1]^encoded[i-1]);
        }
      
        return ans;
    }
};

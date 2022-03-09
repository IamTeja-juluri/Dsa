class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
     
        vector<vector<int>>res;
        
        sort(nums.begin(),nums.end());
        
        int mindiff=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n-1;i++)
            mindiff=min(mindiff,abs(nums[i+1]-nums[i]));
        
        
        for(int i=0;i<n-1;i++){
            vector<int>x;
            int temp=abs(nums[i+1]-nums[i]);
            if(mindiff==temp){
                x.push_back(nums[i]);
                x.push_back(nums[i+1]);
                res.push_back(x);
            }
        }
        
        return res;
    }
};

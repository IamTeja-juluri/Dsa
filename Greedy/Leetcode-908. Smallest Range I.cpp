class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1]-k;
        int min = nums[0] + k;
        int ans = max - min;
        if(ans > 0)
            return ans;
        
        return 0;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        k=k-1;
        while(k--)
        {
           pop_heap(nums.begin(),nums.end());
            nums.pop_back();
        }
        return nums[0];
    }
};

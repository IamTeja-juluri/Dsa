//Also refer techdose link:https://techdose.co.in/4-sum-problem-leetcode-18/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>res;
        if(nums.empty()){
            return res;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n;i++){
            long long target_3 = (long long)target-(long long)nums[i];
            for(int j=i+1; j<n; j++){
                long long target_2 = (long long)target_3 - (long long)nums[j];
                int left = j+1;
                int right = n-1; 
                while(left<right){
                    int sum = nums[left] + nums[right];
                    if(sum<target_2){
                        left++;
                    }
                    else if(sum>target_2){
                        right--;
                    }
                    else if(sum==target_2){
                        vector<int>temp(4,0);
                        temp[0] = nums[i];
                        temp[1]= nums[j];
                        temp[2]= nums[left];
                        temp[3]= nums[right];
                        res.push_back(temp);
                        while(left<right && nums[left]==temp[2]) ++left;
                        while(left<right && nums[right]==temp[3]) --right;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};

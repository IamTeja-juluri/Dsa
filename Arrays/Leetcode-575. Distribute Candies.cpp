class Solution {
public:
    int distributeCandies(vector<int>&nums) {
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]+=1;
        int n=nums.size()/2;
        int size=mp.size();
        return min(size,n);
    }
};

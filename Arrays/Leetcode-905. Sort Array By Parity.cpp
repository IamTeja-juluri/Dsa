class Solution {
public:
    
    static bool compare(const int a,const int b){
        
        int mod1=a%2;
        int mod2=b%2;
        
        return mod1<mod2;
    }
    
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),compare);
        
        return nums;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();
        int carry=1;
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--){
            
            int num=digits[i]+carry;
            if(num<=9){
                ans.push_back(num);
                carry=0;
            }
            else{
                ans.push_back(0);
                carry=1;
            }
        }
        
        if(carry)
            ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

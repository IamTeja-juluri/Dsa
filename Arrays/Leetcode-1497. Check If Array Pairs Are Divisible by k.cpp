class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
       vector<int> rem(k,0);
       
        for(int i=0;i<arr.size();i++)
            rem[( k + (arr[i]%k) )%k]+=1;
        
        if(rem[0]%2)
            return false;
        
        for(int i=1;i<k;i++){
            if(rem[i]!=rem[k-i])
                return false;
        }
        
        return true;
        
    }
};

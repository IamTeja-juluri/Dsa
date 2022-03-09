class Solution {
public:
    
    bool binarySearch(vector<int>&weights,int days,int rsum){
        
        int n=weights.size();
        int sum=0;
        int count=1;
        
        for(int i=0;i<n;i++){
           if(rsum<weights[i])
               return false;
            else if(sum+weights[i] > rsum){
                sum=weights[i];
                count++;
                if(count>days)
                    return false;
            }
            else
                sum+=weights[i];
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        
        int low=0,high=0;
        
        for(auto x:weights)
            high+=x;
        
        int ans=INT_MAX;
        
        while(low<=high){

            int mid=low+(high-low)/2;
            if(binarySearch(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
       
        int n=customers.size();
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)
                sum+=customers[i];
        }
        
        int ones_sum=0;
        
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1)
                ones_sum+=customers[i];
        }
        
        ans=max(ans,ones_sum+sum);
        
        for(int j=0,i=minutes;i<n;i++,j++){
          
            if(grumpy[i]==1)
                ones_sum+=customers[i];
            if(grumpy[j]==1)
                ones_sum-=customers[j];
            
            int curr_sum=ones_sum+sum;
            ans=max(ans,curr_sum);
            
        }
        
        return ans;
    }
};

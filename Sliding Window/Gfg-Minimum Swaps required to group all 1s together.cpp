 int n=nums.size();
        int countones=0;
        
        //number of ones
        for(auto x:nums){
            if(x==1)
                countones+=1;
        }
        
        
        //eliminating the circular property -append array to itself
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        
        int k=countones;
        
        int zeros=0;
        int ans=n;
        
        //first window
        for(int i=0;i<k;i++){
            if(nums[i]==0)
                zeros+=1;
        }
        
        ans=min(zeros,ans);
        //rest of the windows
        for(int j=0,i=k;i<nums.size();i++,j++){
            if(nums[j]==0)
                zeros-=1;
            if(nums[i]==0)
                zeros+=1;
            ans=min(ans,zeros);
        }
        
        return ans;

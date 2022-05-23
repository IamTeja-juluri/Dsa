class Solution {
public:
    
    int firstoption(vector<int>&nums,int first,int second){
       
        int n=nums.size();
        int s=0;
        int ans=0;
        
        vector<int> pref;

        int l=min(first,second);
        int r=max(first,second);
        
        for(auto x:nums){
            s+=x;
            pref.push_back(s);
        }
        
          s=0;
        
        for(int i=0;i<l;i++)
            s+=nums[i];
        
        multiset<int,greater<int> > st;
        
        for(int i=l;i<=(n-r);i++){
            int val=pref[i+r-1]-pref[i-1];
            st.insert(val);
        }
        
     
        auto it=st.begin();
        ans=max(ans,s+*it);
        
        for(int j=0,i=l;i<=(n-r);i++,j++){
            
            s-=nums[j];
            s+=nums[i];
            
            int val=pref[i+r-1]-pref[i-1];
            st.erase(val);
            it=st.begin();
            
            ans=max(ans,s+*it);    
        }
        
        return ans;
    }
    
    
    int secondoption(vector<int>&nums,int first,int second){
        
        int ans=0;
        int n=nums.size();
        int s=0;
        vector<int> pref;
        
        for(auto x:nums){
            s+=x;
            pref.push_back(s);
        }
        
        int l=min(first,second);
        int r=max(first,second);
        
        s=0;
        for(int i=0;i<r;i++)
            s+=nums[i];
        
        multiset<int,greater<int> > st;
        
        for(int i=r;i<=(n-l);i++){
            int val=pref[i+l-1]-pref[i-1];
            st.insert(val);
        }
        
        auto it=st.begin();
        ans=max(ans,*it+s);
        
        for(int j=0,i=r;i<=(n-l);i++,j++){
           
            s-=nums[j];
            s+=nums[i];
            
            int val=pref[i+l-1]-pref[i-1];
            st.erase(val);
            it=st.begin();
            ans=max(ans,*it+s);
            
        }
        
        return ans;
    }
    
    
   
    
    int maxSumTwoNoOverlap(vector<int>& nums, int first, int second) {
        
        int ans1=firstoption(nums,first,second);
        int ans2=secondoption(nums,first,second);
       
        return max(ans1,ans2);
    }
};

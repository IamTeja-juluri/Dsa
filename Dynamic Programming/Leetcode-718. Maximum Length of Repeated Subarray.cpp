//Gives Tle and mle
//O(n^3),O(n^3)
class Solution {
public:
    
    vector<vector<vector<int> > > dp;
    
    int lcs(vector<int>&nums1,vector<int>&nums2,int n,int m,int c){
       
        if(n==-1 || m==-1)
            return c;
        
        if(dp[n][m][c]!=-1)
            return dp[n][m][c];
        
        int c1=c;
        
        if(nums1[n]==nums2[m])
            c1=lcs(nums1,nums2,n-1,m-1,c+1);
         
        int p=max({c1,lcs(nums1,nums2,n-1,m,0),lcs(nums1,nums2,n,m-1,0)});
        
        return dp[n][m][c]=p;
    }
    
    

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        dp.resize(n+1,vector<vector<int> > (m+1,vector<int>(min(n,m),-1) ) );
        
        return lcs(nums1,nums2,n-1,m-1,0);
        
    }
};


// Accepted approach O(n^2),O(n^2)
class Solution {
public:
    
    vector<vector<int> > dp;
    int ans;
    
    int lcs(vector<int>&nums1,vector<int>&nums2,int n,int m){
       
        if(n==-1 || m==-1)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
       
        int c=0;
        
        if(nums1[n]==nums2[m])
            c=1+lcs(nums1,nums2,n-1,m-1);
         
        lcs(nums1,nums2,n-1,m);
        lcs(nums1,nums2,n,m-1);
        
        ans=max(ans,c);
        
        return dp[n][m]=c;
    }
    
    

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        ans=0;
        
        dp.resize(n+1,vector<int>(m+1,-1) );
        
         lcs(nums1,nums2,n-1,m-1);
         
        return ans;
    }
};

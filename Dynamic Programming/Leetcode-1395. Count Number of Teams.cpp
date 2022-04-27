class Solution {
public:
    
    vector<vector<int> >dp1,dp2;
   
    int countTeams1(vector<int>&a,int idx,int n,int c){
        
        if(c==3)
            return 1;
        
        if(idx==n)
            return 0;
        
        if(dp1[idx][c]!=-1)
            return dp1[idx][c];
        
        int cnt=0;
        
        for(int i=idx+1;i<n;i++){
            if(a[i]>a[idx])
                cnt+=countTeams1(a,i,n,c+1);
        }
        
        return dp1[idx][c]=cnt;
         
    }
    
     int countTeams2(vector<int>&a,int idx,int n,int c){
        
        if(c==3)
            return 1;
        
        if(idx==n)
            return 0;
        
        if(dp2[idx][c]!=-1)
            return dp2[idx][c];
        
        int cnt=0;
        
        for(int i=idx+1;i<n;i++){
            if(a[i]<a[idx])
                cnt+=countTeams2(a,i,n,c+1);
        }
        
        return dp2[idx][c]=cnt;
         
    }
    

    
    
    int numTeams(vector<int>& rt) {
        
        int ans=0;
        int n=rt.size();
        
        dp1.resize(n+1,vector<int>(4,-1));
        dp2.resize(n+1,vector<int>(4,-1));
        
        for(int i=0;i<n;i++){
            
            ans=ans+countTeams1(rt,i,n,1);
            ans=ans+countTeams2(rt,i,n,1);
        }
        
        return ans;
    }
};

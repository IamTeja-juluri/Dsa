//Memoization -1

#include<bits/stdc++.h>
using namespace std;

int mincost(int h[],int n,int k,vector<int> &dp){
    
    if(n==0){
        return dp[n]=0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    
    int ans=INT_MAX;
    
    for(int i=1;i<=k;i++){
        
        if((n-i)>=0)
         
         ans=min(ans,abs(h[n]-h[n-i])+mincost(h,n-i,k,dp));
        
    }
    
    return dp[n]=ans;
    
    
}


int main(){
    
    int n,k;
    cin>>n>>k;
    
    int h[n];
    
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
    vector<int> dp(n,-1);
    
    
    cout<<mincost(h,n-1,k,dp)<<endl;
    
    
}
//Memoization 2

#include<bits/stdc++.h>
using namespace std;

int mincost(int h[],int n,int idx,int k,vector<int> &dp){
    
    if(idx==n-1){
        return dp[idx]=0;
    }
    
    if(dp[idx]!=-1){
        return dp[idx];
    }
    
    int ans=INT_MAX;
    
    for(int i=1;i<=k;i++){
        
        if((idx+i)<n)
         
         ans=min(ans,abs(h[idx]-h[idx+i])+mincost(h,n,idx+i,k,dp));
        
    }
    
    return dp[idx]=ans;
    
    
}


int main(){
    
    int n,k;
    cin>>n>>k;
    
    int h[n];
    
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
   vector<int> dp(n,-1);
    
    
    cout<<mincost(h,n,0,k,dp)<<endl;
    
    
}

//Tabulation

#include<bits/stdc++.h>
using namespace std;

int mincost(int h[],int n,int k){
    
    
    vector<int> dp(n,-1);
    
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    
    
    for(int j=2;j<n;j++){
        
        int ans=INT_MAX;
        
      for(int i=1;i<=k;i++){
        
        if((j-i)>=0){
            
          ans=min(ans,abs(h[j]-h[j-i])+dp[j-i]);
          
           }
           
      }   
      
      dp[j]=ans;
    
    }
      
    
    return dp[n-1];
    
}


int main(){
    
    int n,k;
    cin>>n>>k;
    
    int h[n];
    
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
 
    cout<<mincost(h,n,k)<<endl;
    
    
}

//Recursive
#include<bits/stdc++.h>
using namespace std;

long long knapsack(long long wt[],long long val[],long long cap,long long n){
    
    if(n==0 || cap==0)
    return 0;
    
    
    if(cap>=wt[n-1]){
        return max( val[n-1]+knapsack(wt,val,cap-wt[n-1],n-1) ,knapsack(wt,val,cap,n-1) );
    }
    
    return knapsack(wt,val,cap,n-1);
    

}


int main()
{
    long long n,cap;
    cin>>n>>cap;
    
    long long wt[n],val[n];
    
    for(long long i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    
    cout<<knapsack(wt,val,cap,n);

    return 0;
}




//Memoization
#include<bits/stdc++.h>
using namespace std;

long long knapsack(long long wt[],long long val[],long long cap,long long n,vector<vector<long long>> &dp){
    
    if(n==0 || cap==0)
    return 0;
    
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }
    
    if(cap>=wt[n-1]){
        return dp[n][cap]=max( val[n-1]+knapsack(wt,val,cap-wt[n-1],n-1,dp) ,knapsack(wt,val,cap,n-1,dp) );
    }
    
    return dp[n][cap]=knapsack(wt,val,cap,n-1,dp);

}


int main()
{
    long long n,cap;
    cin>>n>>cap;
    
    long long wt[n],val[n];
    
    for(long long i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    
    
     vector<vector<long long > > dp(n+1,vector<long long> (cap+1,-1)); //2D matrix
    
    
    cout<<knapsack(wt,val,cap,n,dp)<<endl;

    return 0;
}

//Tabulation

#include<bits/stdc++.h>
using namespace std;

long long knapsack(long long wt[],long long val[],long long cap,long long n){
    
    
    vector<vector<long long > > dp(n+1,vector<long long>(cap+1,0));
    
    
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=cap;j++){
            
            if(j>=wt[i-1]){
                
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            
        }
        
    }
    
    return dp[n][cap];
    

}


int main()
{
    long long n,cap;
    cin>>n>>cap;
    
    long long wt[n],val[n];
    
    for(long long i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    
    cout<<knapsack(wt,val,cap,n)<<endl;

    return 0;
}




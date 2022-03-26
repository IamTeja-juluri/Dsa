#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1e9+7;
vector<int>dp;
int diceSum(int n){
    
    if(n==0)
        return dp[n]=1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    int ans=0;
    
    for(int i=6;i>=1;i--){
        if((n-i)>=0){
            ans=((ans%mod)+(diceSum(n-i)%mod))%mod;
        }
    }
    
    return dp[n]=ans;
    
}

int32_t main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        dp.resize(n+1,-1);
        cout<<diceSum(n)<<endl; 
    }
    
    
    return 0;
}

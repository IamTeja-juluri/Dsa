//Memoization
//Accepted Approach
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int combinations(int n,vector<long long>&dp){

    if(dp[n]!=-1){
        return dp[n];
    }
    
    if(n==0){
        return 1;
    }

    int count=0;

    for(int i=1;i<=6;i++){
        
        if((n-i)>=0){
         count=((count%mod)+(combinations(n-i,dp)%mod))%mod;
        }

    }
    return dp[n]=count%mod;
    
}


int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	#endif
	  
	  int n;
	  cin>>n;

	   vector<long long > dp(n+1,-1);

     cout<<combinations(n,dp)<<endl;

     

	}
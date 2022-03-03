#include<bits/stdc++.h>
using namespace std;
int countWays(int a[],int sum,int n,int dp[1001][1001]){

if(sum==0)
return dp[n-1][sum]=1;

if(sum<0)
return 0;

if(n==0 && sum!=0)
return 0;

if(dp[n-1][sum]!=-1)
return dp[n-1][sum];

return dp[n-1][sum]=countWays(a,sum-a[n-1],n,dp)+countWays(a,sum,n-1,dp);


}

int main(){

   int sum,n;
   cin>>sum>>n;

   int a[n];

   for(int i=0;i<n;i++)
   cin>>a[i];

   int dp[1001][1001];
   memset(dp,-1,sizeof(dp));

   cout<<countWays(a,sum,n,dp)<<endl;

}

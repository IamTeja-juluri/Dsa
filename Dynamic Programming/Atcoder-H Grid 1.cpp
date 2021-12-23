#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    
    long long  n,m;
    cin>>n>>m;
    
    char a[n][m];
    
    for(long long i=0;i<n;i++){
        
        for(long long j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    vector<vector<long long > > dp(n,vector<long long>(m,0));
    
    for(long long i=0;i<n;i++){
        if(a[i][0]!='#'){
            dp[i][0]=1;
        }
        else{
            break;
        }
    }
    
    
    for(long long i=0;i<m;i++){
        if(a[0][i]!='#'){
            dp[0][i]=1;
        }
        else{
            break;
        }
        
    }
    
    
    for(long long i=1;i<n;i++){
        for(long long j=1;j<m;j++){
            
            if(a[i][j]=='#'){
                continue;
            }
            else{
                dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1]%mod))%mod;
            }
        }
    }
    
    cout<<dp[n-1][m-1]<<endl;
    
}

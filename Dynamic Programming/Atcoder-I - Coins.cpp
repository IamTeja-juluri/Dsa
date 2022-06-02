//refer quesn incase of a doubt
#include<bits/stdc++.h>
using namespace std;

double ans=0;
int n;
vector<double> v;
vector<vector<double>> dp;

//we should have atleast (n+1)/2 heads with/without tails
//thts y we have two cases

double solve(int idx,int x){
    
    if(x==0)
    return 1;
    
    if(idx==-1)
    return 0;
    
    if(dp[idx][x] > -0.9) //imp
    return dp[idx][x];
    
    return dp[idx][x]=v[idx]*solve(idx-1,x-1)+(1-v[idx])*solve(idx-1,x);
}



int main(){
    
    cin>>n;
    
    int xx=(n+1)/2; //we need atleast (n+1)/2 heads
    
    dp.resize(n,vector<double>(xx+1,-1));
    
    for(int i=0;i<n;i++){
        double x;
        cin>>x;
        v.push_back(x);
    }
    
    
    cout<<fixed<<setprecision(10)<<solve(n-1,xx)<<endl;
    
}

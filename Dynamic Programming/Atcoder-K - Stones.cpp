#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,k;
    cin>>n>>k;
    
    int a[n];
    
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int dp[k+1]={0};
   
  //filling  table(from gametheory)
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-a[j] >= 0 && dp[i-a[j]]==0){
                dp[i]=1;
                break;
            }
        }
    }
    
    dp[k]?cout<<"First"<<endl:cout<<"Second"<<endl;
    
}

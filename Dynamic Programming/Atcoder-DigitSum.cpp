#include<bits/stdc++.h>
using namespace std;
string k;
int d;
const int N=1e4;
int modulo=1e9+7;
int memo[N][2][100];
 
int dp(int i,bool last,int mod){
    
    if(i==k.size()){
        return (mod==0);
    }
    
    int &ans=memo[i][last][mod];  //3Dimensional DP
    
    if(ans!=-1){
        return ans;
    }
    
    ans=0;
    
    int till=last?(k[i]-'0'):9;
    
    for(int digit=0;digit<=till;digit++){
        ans+=dp(i+1,last&&(digit==till),(mod+digit)%d);
        ans%=modulo;
    }
    
    return ans;
}
 
 
int32_t main()
{
    cin>>k>>d;
    memset(memo,-1,sizeof(memo));
    cout<<(dp(0,1,0)-1+modulo)%modulo<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    
    ll n;
    scanf("%lld",&n);
    
    ll a[n];
    
    for(ll i=0;i<n;i++)
    scanf("%lld",&a[i]);
    
    ll q;
    scanf("%lld",&q);
    
    ll prf[n]={0};
    prf[0]=a[0];
    
    for(ll i=1;i<n;i++)
        prf[i]=prf[i-1]+a[i];
    
    while(q--){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(x==0)
            printf("%lld\n",prf[y]);
        else
            printf("%lld\n",prf[y]-prf[x-1]);
    }
    
    return 0;
}

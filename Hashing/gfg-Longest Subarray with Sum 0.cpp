#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
           sum+=a[i];
           if(a[i]==0)
               ans=max(ans,1);
           if(sum==0)
               ans=max(ans,i+1);
           if(mp.find(sum)!=mp.end())
               ans=max(ans,i-mp[sum]);
            else
                mp[sum]=i;
        }
     
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}

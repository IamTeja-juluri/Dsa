//Approach 1 very imp
//Remember in worst case scenario maps are fast than unordered maps so in dis problem soln gets accepted
// with maps and unordered maps give tle
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n,k;
        cin>>n>>k;
        
        vector<int> a(n);
        
        for(auto &x:a){
            cin>>x;
        }
        
        string ans="false";
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-2;i++){

           map<int,int> mp;
            
           for(int j=i+1;j<n;j++){
               
               if(mp.find(k-a[j]-a[i])!=mp.end()){
                   ans="true";
                   break;
               }
               mp[a[j]]+=1;
           }
            
        }
        
    
      cout<<ans<<endl;
        
    }
    
    
    return 0;
}


//Approach 2 very imp
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n,k;
        cin>>n>>k;
        
        vector<int> a(n);
        
        for(auto &x:a){
            cin>>x;
        }
        
        string ans="false";
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-2;i++){
            
            int low=i+1,high=n-1;
            
            while(low<high){
                
                int mid=(low+high)/2;
                
                if(a[low]+a[high]+a[i]==k){
                    ans="true";
                    break;
                }
                else if(a[low]+a[high]+a[i]>k){
                    high-=1;
                }
                else{
                    low+=1;
                }
                   
            }
            
        }
        
    
      cout<<ans<<endl;
        
    }
    
    
    return 0;
}

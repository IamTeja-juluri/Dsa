//find max subarray sum
//find starting and last index of maxsum subarray
// If multiple subarrays give the same sum, consider the lexicographically smaller one for the answer.
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    
    while(t--){
       
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int currmax=a[0];
        int maxSofar=a[0];
        int f=0,l=0,p=0;
        
        for(int i=1;i<n;i++){
            
            currmax+=a[i];
            
            if(a[i]>currmax){
                currmax=a[i];
                f=i;
            }
            
            if(maxSofar<currmax){
                maxSofar=currmax;
                p=f;
                l=i;
            }
            
        }
       
        cout<<maxSofar<<" "<<p<<" "<<l<<endl;
    }
    return 0;
}


// Ceil of x is the smallest element which is greater than or equal to x
// Ceil of x doesn’t exist if x is greater than greates element of arr[]


#include<bits/stdc++.h>
using namespace std;


int binary_search(int a[],int n,int x){
    
    int low=0,high=n-1;
    int ans=INT_MAX;
    
    while(low<=high){
        
        int mid=(low+high)/2;
        
        if(a[mid]>=x){
           ans=a[mid];
           high=mid-1;
        }
        else{
            low=mid+1;
        }  
        
    }

    return ans;
    
}


int main() {
      
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    sort(a,a+n);
    
    int q;
    cin>>q;
    
    while(q--){
        
        int x;
        cin>>x;
        int ans=binary_search(a,n,x);
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}

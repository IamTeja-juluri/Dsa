#include<bits/stdc++.h>
using namespace std;

bool Partition(int a[],int n,int k,int sum){
    
    int curr_sum=0,count=1;
    
    for(int i=0;i<n;i++){
        
        if(a[i]>sum){
            return false;
        }
        
        else if(curr_sum+a[i]>sum){
            curr_sum=a[i];
            count+=1;
            if(count>k){
                return false;
            }
        }
        else{
            curr_sum+=a[i];
        }
        
    }
    
    return true;
    
}



int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n,k;
        cin>>n>>k;
        
        int a[n],sum=0;
        
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        
        int low=0,high=sum;
        int ans=INT_MAX;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if( Partition(a,n,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}

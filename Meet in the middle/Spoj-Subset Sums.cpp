#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>subsetSums(vector<int>&nums){
    
    int n=nums.size();
    vector<int>arr;
    
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if( ((i>>j)&1) == 1 ){
                sum+=nums[j];
            }
        }
        arr.push_back(sum);
    }
    
    return arr;
    
}



int32_t main(){
    
    #ifndef ONLINE_JUDGE
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
    #endif
    
    int n,a,b;
    cin>>n>>a>>b;
    
    vector<int>v(n);
    
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    
    vector<int>left,right;
    
    for(int i=0;i<n;i++){
        if(i<(n/2))
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    
    vector<int>lsum=subsetSums(left);
    vector<int>rsum=subsetSums(right);
 
    int count=0;
    
    sort(rsum.begin(),rsum.end());
    
    for(auto x:lsum){
        count=count+upper_bound(rsum.begin(),rsum.end(),b-x)-lower_bound(rsum.begin(),rsum.end(),a-x);
    }
    
    cout<<count<<endl;
    
}

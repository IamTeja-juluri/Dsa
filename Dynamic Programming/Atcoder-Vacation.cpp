//Memoization
#include<bits/stdc++.h>
using namespace std;

int solveA(int);
int solveB(int);
int solveC(int);

 
vector<int> a,b,c;
vector<int> dpa,dpb,dpc;

int solveA(int n){
      
    if(n==0){
        return dpa[n]=a[n];
    }
    
    if(dpa[n]!=-1)
    return dpa[n];
    
    return dpa[n]=max(solveB(n-1),solveC(n-1))+a[n];
    
}


int solveB(int n){
     
    if(n==0){
        return dpb[n]=b[n];
    }
     
    if(dpb[n]!=-1)
    return dpb[n];
 
    return dpb[n]=max(solveA(n-1),solveC(n-1))+b[n];
    
}


int solveC(int n){
    
   
    if(n==0){
        return dpc[n]=c[n];
    }
   
     if(dpc[n]!=-1){
        return dpc[n];
    }
    
    return dpc[n]=max(solveA(n-1),solveB(n-1))+c[n];
    
}


int main()
{
    
    int n;
    cin>>n;
    
   a.resize(n),b.resize(n),c.resize(n);
    
   dpa.resize(n,-1),dpb.resize(n,-1),dpc.resize(n,-1);
   
  
    for(int i=0;i<n;i++){
        
        cin>>a[i]>>b[i]>>c[i];
        
    }
    
    cout<<max(solveA(n-1),max(solveB(n-1),solveC(n-1)));

    return 0;
}

//Tabulation

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    
    int a[n][3];
    
    for(int i=0;i<n;i++){
        
        for(int j=0;j<3;j++){
            
            cin>>a[i][j];
            
        }
        
    }
    
     vector<vector<int> > dp;

     for(int i=0;i<n;i++){

       vector<int> v;
        
        for(int j=0;j<3;j++){
            
            v.push_back(a[i][j]);    
            
        }
        
        dp.push_back(v);
        
    }
    
    
    for(int i=1;i<n;i++){
        
        
        for(int j=0;j<3;j++){
            
            
            for(int k=0;k<3;k++){
                
                if(k!=j)
                dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                
            }
            
        }
         
         
   }
        
    /*
    int ans=*max_element(dp[n-1][0],dp[n-1]+3); */
    
    int ans=0;
    ans=max(dp[n-1][0],ans);
    ans=max(ans,dp[n-1][1]);
    ans=max(ans,dp[n-1][2]);
    
    cout<<ans<<endl;
    
}

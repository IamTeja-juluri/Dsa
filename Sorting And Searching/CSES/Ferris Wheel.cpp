#include<bits/stdc++.h>
using namespace std;
int main(){
   
   #ifndef ONLINE_JUDGE
	freopen("inputss.txt","r",stdin);
	freopen("outputss.txt","w",stdout);
   #endif

	int n,x;
	cin>>n>>x;

	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	sort(a,a+n);

	int p1=0,p2=n-1,ans=0;

	while(p1<=p2){
       
       if(p1!=p2 and a[p1]+a[p2]<=x){
        p1+=1;
        p2-=1;
       }
       else
       	p2-=1;

      ans+=1;
	}
   
   cout<<ans<<endl;
}

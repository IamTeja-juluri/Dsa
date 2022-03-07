//Kadanes Algorithm

#include<bits/stdc++.h>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	 freopen("inputss.txt","r",stdin);
	 freopen("outputss.txt","w",stdout);
	#endif

  int n;
  cin>>n;

  long a[n];

  for(int i=0;i<n;i++)
  	cin>>a[i];

   long long msf=a[0],meh=a[0];

  for(int i=1;i<n;i++){
      msf=msf+a[i];
      if(msf<a[i])
        msf=a[i];
      if(meh<msf)
        meh=msf;
  }
  
  cout<<meh<<endl;

}
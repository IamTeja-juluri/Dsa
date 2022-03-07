#include<bits/stdc++.h>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	 freopen("inputss.txt","r",stdin);
	 freopen("outputss.txt","w",stdout);
	#endif

  int n;
  cin>>n;

  int a[n];
  set<int> st;

  for(int i=0;i<n;i++){
  	cin>>a[i];
  	st.insert(a[i]);
  }
  
  cout<<st.size()<<endl;

}
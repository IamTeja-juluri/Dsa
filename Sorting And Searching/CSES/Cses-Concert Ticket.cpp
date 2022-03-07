#include<bits/stdc++.h>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	 freopen("inputss.txt","r",stdin);
	 freopen("outputss.txt","w",stdout);
	 #endif

     int n,m;
     cin>>n>>m;

     int h[n],t[m];

     for(int i=0;i<n;i++)
     	cin>>h[i];
     

     for(int i=0;i<m;i++)
     	cin>>t[i];
     
     multiset<int> st;

     for(int i=0;i<n;i++)
       st.insert(h[i]);

     for(int i=0;i<m;i++){
          auto it =st.lower_bound(t[i]);
          if(it!=st.end() && (*it)==t[i]){
          	cout<<*it<<endl;
          	st.erase(it);
          }
          else if(it!=st.begin()){
          	    it--;
          	    cout<<*it<<endl;
          	    st.erase(it);
          }
          else{
          	cout<<-1<<endl;
          }

     }

}
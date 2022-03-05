#include<bits/stdc++.h>
using namespace std;

// use maps for avoiding duplicates 
void subsequences(string s,string ans,int idx){

     if(idx==s.size()){

       cout<<ans<<endl;
     	return ;
     }

   subsequences(s,ans+s[idx],idx+1);
   subsequences(s,ans,idx+1);

}



int main(){
   
   #ifndef ONLINE_JUDGE
	freopen("inputs.txt","r",stdin);
	freopen("output.txt","w",stdout);
  #endif
   
   string s;
   cin>>s;
   subsequences(s,"",0);


}
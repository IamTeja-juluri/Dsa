//AC
//Codeforces Round #776 (Div. 3
#include<bits/stdc++.h>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	  freopen("inputcf.txt","r",stdin);
	  freopen("outputcf.txt","w",stdout);
	  #endif
	  
	int t;
	cin>>t;

	while(t--){
        
        string s;
        cin>>s;

        char ch;
        cin>>ch;

        vector<int> ans;

        for(int i=0;i<s.size();i++){
        	if(s[i]==ch)
        		ans.push_back(i);
        }
        
        int n=s.size();
        string res="NO";
        
        for(int i=0;i<ans.size();i++){
  
               int l=ans[i];
               int r=n-ans[i]-1;
               if(l%2==0 && r%2==0){
               	res="YES";
               	break;
               }
        }
         
         cout<<res<<endl;
    }

}

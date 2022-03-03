#include<bits/stdc++.h>
using namespace std;

string s;
vector<string>v;


bool ispalindrome(int l,int r){

    while(l<=r){
    	if(s[l++]!=s[r--]){
           return false;
    	}
    }
   
   return true;
}


void palindromicPartioning(int idx){

	if(idx>=s.size()){
		for(auto x:v){
			cout<<x<<endl;
		}
		return;
	}

   for(int i=idx;i<s.size();i++){

     if(ispalindrome(idx,i)){
       
       v.push_back(s.substr(idx,i+1-idx));
     	 palindromicPartioning(i+1);
       v.pop_back();   

     }

   }

}


int main(){

    #ifndef ONLINE_JUDGE
     freopen("input4.txt","r",stdin);
     freopen("output4.txt","w",stdout);
    #endif
     
     cin>>s;
     
     palindromicPartioning(0);

     
    
}
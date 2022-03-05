#include<bits/stdc++.h>
using namespace std;

// use maps for avoiding duplicates 
unordered_map<string,int> mp;

void subsequences(string s,string ans,int idx){

     if(idx==s.size() ){
       
       if(mp.count(ans)==0){
         mp[ans]+=1;
         cout<<ans<<endl;
       }
      
     	return ;
     }
   
   ans.push_back(s[idx]);
   subsequences(s,ans,idx+1);
   ans.pop_back();
   subsequences(s,ans,idx+1);

}



int main(){
   
   #ifndef ONLINE_JUDGE
	freopen("inputx.txt","r",stdin);
	freopen("outputx.txt","w",stdout);
  #endif
   
   string s;
   cin>>s;
   subsequences(s,"",0);


}
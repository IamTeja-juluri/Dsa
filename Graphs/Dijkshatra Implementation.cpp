#include<bits/stdc++.h>
using namespace std;


void dijkhatra(){

  set<pair<int,int> > st;
  vector<int> dist(v,INT_MAX);

  st.insert({0,src});

  while(!st.empty()){
    
      auto it=st.begin();
      int node=it->second;
      int currdist=it->first;
      st.erase(it);
     
      for(auto nbrpair:l[node]){
           
           int nbr=nbrpair.second;
           int weight=nbrpair.first;
           
           if(currdist+weight<dist[nbr]){
              
              auto f=st.find({dist[nbr],nbr});
              if(f!=s.end()){
              	s.erase(f);
              }
            
            dist[nbr]=currdist+weight;
            s.insert({dist[nbr],nbr});
           }

      }


  }



}


int main(){




}
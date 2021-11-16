/*
In a school, there are N students in a class numbered from 1,2,3..N.
During the play time in school, drill master wants to split them into 
two teams based on their interest.
 
If the pair of students want to play opposite each other, drill master should 
put them in different teams, e.g. pair[i] = (A,B), it is not allowed to 
put A and B in same team.
   
You need to find out wether is it possible to put everyone into two teams or not
return true if it is possible, otherwise false.
 
Input Format:
----------------
Line-1 -> Two Integers, N and P, number of students N, number of pairs P.
Next P lines -> Two integers, one pair[i], where 'i' is from 0 to P-1


Output Format:
------------------
Print a boolean result.
 
 
Sample Input-1:
-------------------
 5 4
 1 2
 1 3
 2 4
 3 5
 
Sample Output-1:
---------------------
 true

Explanation: 
----------------
 team1 [1,4,5], team2 [2,3]
 
 
Sample Input-2:
-------------------
 5 5
 1 2
 2 3
 3 4
 4 5
 1 5
  
 Sample Output-2:
 ---------------------
  false
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
  
  int v;
  list<pair<int,int> > l;
  
  public:
  
  Graph(int v){
      this->v=v;
  }
  
  void addEdge(int x,int y){
      l.push_back({x,y});
  }
  
  int findSet(int i,int parent[]){
      
      if(parent[i]==-1)
      return i;
      
      return findSet(parent[i],parent);
      
  }
  
  
  void union_set(int x,int y,int parent[]){
     
     int s1=findSet(x,parent);
     int s2=findSet(y,parent);
     
     if(s1!=s2){
         parent[s2]=s1;
     }
     
  }
  
  bool res(){
      
      int *parent=new int[v];
      
      for(int i=0;i<v;i++){
          parent[i]=-1;
      }  
      
      for(auto edge:l){
          
          int i=edge.first;
          int j=edge.second;
          
          int s1=findSet(i,parent);
          int s2=findSet(j,parent);
        
          if(s1!=s2){
              union_set(s1,s2,parent);
          } 
          else{
              return false;
          }
          
      }
       
      return true;
      
  }
  
  
    
};

int main(){
    
    int n,p;
    cin>>n>>p;
    
     Graph g(n);
     
      while(p--){
          
          int x,y;
          cin>>x>>y;
          g.addEdge(x-1,y-1);
          
      }
     
     cout<<g.res()<<endl;
    
}

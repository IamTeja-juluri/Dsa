#include<bits/stdc++.h>
using namespace std;
class Node{
    
    public:
    char data;
    unordered_map<char,Node*>mp;
    int wordcount;
    Node(char d){
        data=d;
        wordcount=1;
    }
};

class Trie{
 public:
  Node* root;
  
  Trie(){
      root=new Node('\0');
  }
  
  void insert(string word){
      
      Node* curr=root;
      
      for(char ch:word){
          
          if(curr->mp.count(ch)==0){
              Node* newNode=new Node(ch);
              curr->mp[ch]=newNode;
          }
          else{
              curr->wordcount+=1;
          }
          curr=curr->mp[ch];
          
      }
      
  }
  
  int countStrings(string prefix){
      
      int count=0;
      Node* curr=root;
      
       for(int i=0;prefix[i]!='\0';i++){
           
           if(curr->mp.count(prefix[i])==0){
              return count;
           }
           else{
            count=curr->wordcount;
            curr=curr->mp[prefix[i]];   
           }
           
           
       }
       
      return count;
      
  }
  
  
   
};

int main(){
    
    Trie t;
    
    vector<string> v{"abba","abbb","abbc","abbd","abaa","abca"};
    
    for(int i=0;i<v.size();i++){
        t.insert(v[i]);
    }
    
    string prefix="abbg";
   cout<< t.countStrings(prefix);
   //output is 4 because
   //“abba”, “abbb”, “abbc” and “abbd” are the matching strings with prefix abb.
    
}

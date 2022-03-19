//Trie approach gives mle and tle
class Node{
    
  public:
  char data;
  unordered_map<char,Node*>mp;
  bool isTerminal;
  
  Node(char d){
      data=d;
      isTerminal=false;
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
        
        for(auto ch:word){
            if(curr->mp.count(ch)==0){
                Node* newNode=new Node(ch);
                curr->mp[ch]=newNode;
            }
            curr=curr->mp[ch];
        }
        
        curr->isTerminal=true;
    }
    
    bool search(string word){
        
        Node* curr=root;
        
        for(auto ch:word){
            if(curr->mp.count(ch)==0){
                return false;
            }
            curr=curr->mp[ch];
        }
        
       return curr->isTerminal;   
    }
    
    
};



class Solution {
public:
    
    
string binarySearch(string &s){
    
    int n=s.size();
    int low=0;
    int high=n-1;
    int longest=0;
    string ans="";
        
        //construct Trie
    
    while(low<=high){
        
        Trie t;
        
        int mid=low+(high-low)/2;
        bool found=false;
        
        for(int i=0;i+mid<=n;i++){
            
            string x=s.substr(i,mid);
            if(t.search(x)){
              found=true;
              ans=x;
              break;    
            }
            else
                t.insert(x);
            
        }
        
        if(found)
            low=mid+1;
        else
           high=mid-1;
        
    }
    
    return ans;
}
    
    string longestDupSubstring(string s) {
        
        return binarySearch(s);
        
    }
};
//using set gives mle and tle again
class Solution {
public:
    
    
string binarySearch(string &s){
    
    int n=s.size();
    int low=0;
    int high=n-1;
    int longest=0;
    string ans="";
        
    
    while(low<=high){
        
        
        unordered_set<string> mp;
        
        int mid=low+(high-low)/2;
        bool found=false;
        
        for(int i=0;i+mid<=n;i++){
            
            string x=s.substr(i,mid);
            if(mp.find(x)!=mp.end()){
              found=true;
              ans=x;
              break;    
            }
            else
                mp.emplace(x);
            
        }
        
        if(found)
            low=mid+1;
        else
           high=mid-1;
        
    }
    
    return ans;
}
    
    string longestDupSubstring(string s) {
        
        return binarySearch(s);
        
    }
};




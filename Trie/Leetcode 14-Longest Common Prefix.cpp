class Node{
    public:
    char data;
    unordered_map<char,Node*> m;
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
      root=new Node('/0');
  }  
    void insert(string word){
        
        Node* curr=root;
        
        for(char ch:word){
            
            if(curr->m.count(ch)==0){
                Node* newNode=new Node(ch);
                curr->m[ch]=newNode;
            }
            curr=curr->m[ch];
        }
         curr->isTerminal=true;
    }
  
    string commonPrefix(string word){
        
        Node* curr=root;
        string ans="";
        
        for(char ch:word){
            
            if( (curr->m.size()>1) || ( curr->isTerminal==true && curr->m.size()==1 ) ){
                return ans;
            }
          
            else if(curr->isTerminal==false && curr->m.size()==1){
                ans=ans+ch;
            }
            curr=curr->m[ch];
            
        }
    
        return ans;
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie t;
        
        for(string word:strs){
             t.insert(word);
        }
        
        return t.commonPrefix(strs[0]);
        
    }
};

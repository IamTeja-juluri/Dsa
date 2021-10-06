class Node{
    
  public:
    char data;
    unordered_map <int,Node*> m;
    bool isTerminal;
    
    Node(char d){
        data=d;
        isTerminal=false;
    }
    
};
class Trie {
public:
    Node* root;
    Trie() {
      root=new Node('/0');  
    }
    
    void insert(string word) {
        
        Node* temp=root;
        for(char ch:word){
            
            if(temp->m.count(ch)==0){
                Node* newNode=new Node(ch);
                temp->m[ch]=newNode;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        
        Node* curr=root;
        
        for(char ch:word){
            if(curr->m.count(ch)==0){
                return false;
            }
            curr=curr->m[ch];
        }
        
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        
        Node* curr=root;
        
        for(char ch:prefix){
    
            if(curr->m.count(ch)==0){
                return false;
            }
            curr=curr->m[ch];
            
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL){
            return NULL;
        }
        
        if(!root->left && !root->right){
            return root;
        }
        
        queue<Node*> q;
        
        q.push(root);
        
         while(!q.empty()){
             
             int n=q.size();
             
             Node* dummy=new Node(0);
             
             for(int i=1;i<=n;i++){
                 
                 Node*curr=q.front();
                 
                 if(curr->left){
                     q.push(curr->left);
                     dummy->next=curr->left;
                     dummy=dummy->next;
                     
                 }
                 
                 if(curr->right){
                     q.push(curr->right);
                     dummy->next=curr->right;
                     dummy=dummy->next;
                     
                 }
                 q.pop();
                 
             }
            
         }
        return root;
    
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        Node* curr=head;
        
        while(curr){    //inserting duplicate nodes
            
            Node*temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;
            
        }
        
       curr=head; 
        
        
       while(curr){          //initialising random pointers for every duplicate node
           
      
           if(curr->next) //random can also be null 
            curr->next->random = curr->random ?
                                 curr->random->next : curr->random;
 
           curr = curr->next?curr->next->next:curr->next; 

           
       } 
        
        Node* original=head,*copy=head->next;
        Node* res=copy;
        
        while(original && copy){   //separating clone list and orginal list
            
           original->next=original->next->next;
           copy->next=copy->next?copy->next->next:copy->next;
           original=original->next;
           copy=copy->next;
 
            
        }
        
        return res;
        
        
        
    }
};

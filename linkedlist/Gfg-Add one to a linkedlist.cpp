/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head){
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
         return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        
        Node* curr=reverse(head); 
         Node* newNode=NULL;
         
         int sum=0;
         int carry=1;
         
         Node*dummyHead=NULL;
         Node* res=NULL;
         
        while(curr){
            
           sum=carry+(curr?curr->data:0); 
           
           carry=sum>9?1:0;
           newNode=new Node(sum%10);
            
            if(dummyHead==NULL){
                dummyHead=newNode;
                res=newNode;
            }
            else{
                res->next=newNode;
                res=res->next;
            }
            
            if(curr)
            curr=curr->next;
        }
        
        if(carry){
            res->next=new Node(carry);
            res=res->next;
        }
        
        return res=reverse(dummyHead);
    }
};

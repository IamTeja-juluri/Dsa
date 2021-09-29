class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        if(head==NULL)
        return NULL;
        
        Node*even_node=new Node(0);
        Node*odd_node=new Node(0);
        
        Node*curr=head;
        Node*even_head=NULL;
        Node*odd_head=NULL;
        
        while(curr){
            
            if((curr->data)%2==0){
                if(even_head==NULL){
                    even_head=curr;
                }
                even_node->next=curr;
                even_node=curr;
            }
            else{
                if(odd_head==NULL){
                    odd_head=curr;
                }
                odd_node->next=curr;
                odd_node=curr;
            }
            curr=curr->next;
        }
        
        
        if(!even_head){   // if no even numbers exists
            return odd_head;
        }
        
        if(!odd_head){    //  if no odd numbers exists
            return even_head;
        }
                             // if both exists
         odd_node->next=NULL;
        even_node->next=odd_head;
        return even_head;
        
    }
};

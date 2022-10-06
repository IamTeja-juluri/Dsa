class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       
      if(head==NULL){
       Node* newNode=new Node(data);
       newNode->next=newNode;
       return newNode;
      }
      
      Node* lastNode=head;
      
      while(lastNode->next!=head)
          lastNode=lastNode->next;
      
      if(data<=head->data){
          Node* newNode=new Node(data);
          newNode->next=head;
          lastNode->next=newNode;
          return newNode;
      }
      
      if(data>=lastNode->data){
          Node* newNode=new Node(data);
          newNode->next=head;
          lastNode->next=newNode;
          return head;
      }
       
      Node* first=head;
      Node* second=first->next;
       
      Node* tempHead=head;
      
      while(second->next!=first){
          
          if(data>=first->data and data<=second->data){
              Node* newNode=new Node(data);
              newNode->next=second;
              first->next=newNode;
              break;
          }
          first=second;
          second=second->next;
      }
       
       return head;
       
    }
};

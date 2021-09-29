class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
      if(head==NULL)
        return NULL;

        if(head->next==NULL)
        return head;
         
        Node* curr=head;
        Node* res=head;
        
        unordered_map<int,int> mp;
        mp[curr->data]+=1;
        curr=curr->next;

        while(curr!=NULL){
          if(mp.count(curr->data)==0){
               mp[curr->data]+=1;
              res->next=curr;
              res=curr;
          }
         curr=curr->next;
        }

        res->next=NULL;
        return head;
    }
};

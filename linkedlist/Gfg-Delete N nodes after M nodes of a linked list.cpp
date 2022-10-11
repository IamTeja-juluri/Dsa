
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        
        
        struct Node* currNode=head;
        
        while(currNode!=NULL){
            
            
            for(int i=1;i<M and currNode!=NULL;i++)
            currNode=currNode->next;
            
            if(currNode==NULL)
            return;
            
            struct Node* nextNode=currNode->next;
            
            for(int i=1;i<=N and nextNode!=NULL;i++)
            nextNode=nextNode->next;
            
            currNode->next=nextNode;
            currNode=nextNode;
            
        }
        
        
    }
};

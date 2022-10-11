class Solution {
public:
    
    ListNode* swapNode;
    
    void helper(ListNode* head,int &k){
        
        if(head==NULL)
            return;
        helper(head->next,k);
        k-=1;
        if(k==0)
          swapNode=head;
        return;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        int i=1;
        ListNode* currNode=head;
        
        while(i<k and currNode!=NULL){
            i+=1;
            currNode=currNode->next;
        }
        
        helper(head,k);
        swap(swapNode->val,currNode->val);
        return head;
    }
};

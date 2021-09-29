class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
        if(lists.size()==0)
            return NULL;
        
        int k=lists.size();
        
        priority_queue<int,vector<int >,greater<int> > pq;
        
        for(int i=0;i<k;i++)
        {
            while(lists[i])
            {
                 pq.push( (lists[i])->val);
                lists[i]=(lists[i])->next;
            }
            
        }
        
        ListNode* head=new ListNode();
        ListNode* res=head;
        
        res->next=NULL;
        
        while(!pq.empty()){
      
            ListNode* temp=new ListNode();
            temp->next=NULL;
            res->next=temp;
            res=temp;
            res->val=pq.top();
            pq.pop();
            
        }
        
       return head->next;
    }
};

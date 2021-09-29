class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    ListNode* temp1=head;
     ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL)
        {
            temp2=temp2->next->next;
            temp1=temp1->next;
        }
        return temp1;
    }
};

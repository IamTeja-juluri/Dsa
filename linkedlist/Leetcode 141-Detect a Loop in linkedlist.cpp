class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(s.find(temp)==s.end())
           s.insert(temp);
            else
                return true;
            temp=temp->next;
        }
        return false;
    }
};

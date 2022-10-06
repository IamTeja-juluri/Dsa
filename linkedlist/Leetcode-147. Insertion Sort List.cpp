/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//swapping values
class Solution {
public:
    
    ListNode* insertionSortList(ListNode* head) {
        
    
    for(auto cur = head; cur; cur = cur -> next) 
        for(auto x = head; x != cur; x = x-> next) 
                if(x -> val > cur -> val) 
                    swap(x -> val, cur -> val);
        return head;    
    
        
    }
};

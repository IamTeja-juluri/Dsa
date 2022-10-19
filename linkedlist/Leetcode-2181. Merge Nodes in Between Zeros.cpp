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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        
        ListNode* currNode=head->next;
        ListNode* newHead=NULL;
        ListNode* newCurr=NULL;
        
        while(currNode!=NULL){
            int temp_sum=0;
            while(currNode->val!=0){
                temp_sum+=currNode->val;
                currNode=currNode->next;
            }
            
            if(newHead==NULL){
                newHead=new ListNode(temp_sum);
                newCurr=newHead;
            }
            else{
                newCurr->next=new ListNode(temp_sum);
                newCurr=newCurr->next;
            }
            currNode=currNode->next;
        }
        
        return newHead;
    }
};

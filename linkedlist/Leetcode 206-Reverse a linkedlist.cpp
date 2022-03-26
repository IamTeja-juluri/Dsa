//iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};
//Recursive approach

class Solution {
public:
  
    ListNode* reverseList(ListNode* head) {
     
        if(head==NULL)
            return NULL;
         if(head->next==NULL)
         {
             return head;
         }
        
        ListNode* temp=reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
        
    }
};

//Java 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// class Solution {
//     public ListNode reverseList(ListNode head) {
        
//         if(head==null)
//             return null;
        
//         if(head.next==null)
//             return head;
        
//         ListNode curr=reverseList(head.next);
        
//         head.next.next=head;
//         head.next=null;
        
//         return curr;
        
      //  Iterative
//         if(head==null)
//             return null;
        
//         ListNode prev=null,curr=head;
        
//         while(curr!=null){
//             ListNode temp=curr.next;
//             curr.next=prev;
//             prev=curr;
//             curr=temp;
//         }
        
//         return prev;
        
//     }
//}



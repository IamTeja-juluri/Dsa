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
class Solution {
    public ListNode partition(ListNode head, int x) {
        
        if(head==null)
            return null;
      
      ListNode dummy1=new ListNode();
      ListNode dummy2=new ListNode();
           
      ListNode head1=dummy1;
      ListNode head2=dummy2;
        
      ListNode curr=head;
       
      while(curr!=null){
          if(curr.val<x){
              dummy2.next=curr;
              dummy2=dummy2.next;
          }
          else{
              dummy1.next=curr;
              dummy1=dummy1.next;
          }
          curr=curr.next;
      }  
      
      dummy1.next=null;
      dummy2.next=head1.next;  
      return head2.next;  
}
}

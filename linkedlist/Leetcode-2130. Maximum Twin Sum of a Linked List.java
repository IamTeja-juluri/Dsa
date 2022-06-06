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
    
    //idea is to reverse second half of list
    //or we can use stack
    //recursive
    ListNode reverse(ListNode head){
       
        if(head==null)
            return null;
        
        if(head.next==null)
            return head;
        
        ListNode temp=reverse(head.next);
        head.next.next=head;
        head.next=null;
        return temp;
    }
    //iterative
    ListNode reverse(ListNode head){
        
        ListNode curr=head;
        ListNode prev=null;
        
        while(curr!=null){
            ListNode temp=curr.next;
            curr.next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    public int pairSum(ListNode head) {
        
        ListNode slow=head;
        ListNode fast=head.next;
        
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        
        ListNode curr2=reverse(slow.next);
        
        int ans=Integer.MIN_VALUE;
        ListNode curr1=head;
        
        while(curr2!=null){
            ans=Math.max(ans,curr1.val+curr2.val);
            curr1=curr1.next;
            curr2=curr2.next;
        }
        
        return ans;
    }
}

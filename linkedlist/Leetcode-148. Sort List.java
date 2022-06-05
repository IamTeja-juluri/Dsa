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
    
    public ListNode findMid(ListNode head){
        
        ListNode slow=head;
        ListNode fast=head.next;
        
        while((fast!=null) && (fast.next!=null)){
            slow=slow.next;
            fast=fast.next.next;
        }
        
        return slow;
    }
    
    public ListNode merge(ListNode a,ListNode b){
        
        if(a==null)
            return b;
        
        if(b==null)
            return a;
    
        
        if(a.val<b.val){
            a.next=merge(a.next,b);
            return a;
        }
        else{
            b.next=merge(a,b.next);
            return b;
        }
        
        
    }
    
    
    public ListNode mergeSort(ListNode head){
        
        if(head==null || head.next==null)
            return head;
        
        ListNode mid=findMid(head);
        ListNode a=head;
        ListNode b=mid.next;
        mid.next=null;
        a=mergeSort(a);
        b=mergeSort(b);
        
        return merge(a,b);
        
    }
    
    
    
    
    public ListNode sortList(ListNode head) {
        
        if(head==null)
            return null;
        
        return mergeSort(head);
    }
}

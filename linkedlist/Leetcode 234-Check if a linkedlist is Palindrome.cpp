//Three approaches
//Approach 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
         stack<int> st;
        
        ListNode*curr=head;
        
        while(curr!=NULL){
            st.push(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        
        while(!st.empty()){
            
            if(st.top()==curr->val){
                st.pop();
                curr=curr->next;
            }
            else{
                return false;
            }
        }
        
        return true;
     
    }
};
//Approach 2-IMP  Optimal
/* Here we divide list into two halves(left and Right).We reverse the right half of list and then compare the elements of first list and second list .For eg:first element of first half is checked with first element of second half
and then after checking we reverse second half den return the head (we should ensure that list is not modified) while  returning */


class Solution {
public:
    
    ListNode* reverseList(ListNode* slow){
        
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        
        while(curr!=NULL){
            ListNode*next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
       ListNode*fast=head;
       ListNode*slow=head;
        
       while(fast!=NULL && fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
        
       if(fast){
           slow=slow->next;
       } 
       slow=reverseList(slow);
        
       while(slow!=NULL){
           
           if(slow->val!=head->val){
               return false;
           }
           slow=slow->next;
           head=head->next;
       } 
        
        return true;
           
    }
};

//Approach 3 Recursive imp
//gfg soln
bool isPalindromeUtil(struct node** left, struct node* right)
{
    /* stop recursion when right becomes NULL */
    if (right == NULL)
        return true;
 
    /* If sub-list is not palindrome then no need to
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;
 
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data);
 
    /* Move left to next node */
    *left = (*left)->next;
 
    return isp1;
}
 
// A wrapper over isPalindromeUtil()
bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head, head);
}

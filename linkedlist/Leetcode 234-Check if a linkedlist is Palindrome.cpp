//Two approaches
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


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
    vector<int> nextLargerNodes(ListNode* head) {
        
        
        
        ListNode* curr=head;
        vector<int> res;
        
        if(head==NULL)
            return res;
        
         int cnt=0;
        
        while(curr){
            cnt+=1;
            curr=curr->next;
        }
        
         res.resize(cnt,0);
    
        stack<pair<int,int> > st;
        curr=head;
        int i=0;
        
        while(curr!=NULL){
            
            while(!st.empty() && curr->val > st.top().second){
                res[st.top().first]=curr->val;
                st.pop();
            }
            
            st.push({i,curr->val});
            curr=curr->next;
            i+=1;
        }
    
        
        return res;
    }
};

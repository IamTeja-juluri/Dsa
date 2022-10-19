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
    int numComponents(ListNode* head, vector<int>& nums) {
     
        if(head==NULL)
            return 0;
        
        int cnt=0;
        unordered_set<int> st;
        
        for(auto x:nums)
            st.insert(x);
        
        ListNode* currNode=head;
        
        while(currNode!=NULL){
            
            if(st.find(currNode->val)==st.end()){
                currNode=currNode->next;
                continue;
            }
            else{
                while(currNode!=NULL and st.find(currNode->val)!=st.end())
                    currNode=currNode->next;
                cnt+=1;
            }
            
        }
        
        return cnt;
    }
};

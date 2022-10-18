class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    
        vector<int> ans,res;
        
        if(head==NULL or head->next==NULL or head->next->next==NULL)
            return {-1,-1};
        
        ListNode* prev=head;
        ListNode* currNode=head->next;
        ListNode* nextNode=currNode->next;
        
        int  i=1;
        
        while(nextNode!=NULL){
            if( (currNode->val>prev->val and currNode->val>nextNode->val) || (currNode->val<prev->val and currNode->val<nextNode->val) )
                ans.push_back(i);
            prev=currNode;
            currNode=nextNode;
            nextNode=nextNode->next;
            i+=1;
        }
        
        
        int minDist=INT_MAX;
        int maxDist=INT_MIN;
        
        if(ans.size()==0 or ans.size()==1)
            return {-1,-1};
        
        maxDist=ans[ans.size()-1]-ans[0];
        
        for(int i=0;i<ans.size()-1;i++)
            minDist=min(minDist,ans[i+1]-ans[i]);
        
        res.push_back(minDist);
        res.push_back(maxDist);
        
        
        return res;
    }
};

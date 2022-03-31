/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>res;
        
        if(root==NULL)
            return res;
        
        queue<Node*>q;
        q.push(root);
        vector<int>v;
        v.push_back(root->val);
        
        while(!q.empty()){
            res.push_back(v);
            v.clear();
            int n=q.size();
            for(int i=1;i<=n;i++){
                  Node* curr=q.front();
                  q.pop();
                for(int j=0;j<curr->children.size();j++){
                    if(curr->children[j]!=NULL)
                    q.push(curr->children[j]);
                    v.push_back(curr->children[j]->val);
                }
            }
        }
        return res;
    }
};

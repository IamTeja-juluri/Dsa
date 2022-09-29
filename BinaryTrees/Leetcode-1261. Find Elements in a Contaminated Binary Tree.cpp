/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    
    unordered_set<int> st;
    
    FindElements(TreeNode* root) {
        root->val=0;
        st.insert(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode->left){
                int counter=2*(currNode->val)+1;
                currNode->left->val=counter;
                st.insert(counter);
                q.push(currNode->left);
            }
            if(currNode->right){
                int counter=2*(currNode->val)+2;
                currNode->right->val=counter;
                st.insert(counter);
                q.push(currNode->right);
            }
        }
    }
    
    bool find(int target) {
        if(st.find(target)==st.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

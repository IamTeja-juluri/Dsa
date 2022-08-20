/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
        
//         if(root==NULL)
//             return "";
            
//         queue<TreeNode*> q;
        
//         q.push(root);
//         string ans=to_string(root->val)+",";
        
//         while(!q.empty()){
//                 TreeNode* currNode=q.front();
//                 q.pop();
//                 if(currNode->left){
//                     q.push(currNode->left);
//                     ans=ans+to_string(currNode->left->val)+",";
//                 }
//                 else
//                     ans=ans+"#,";
//                  if(currNode->right){
//                     q.push(currNode->right);
//                     ans=ans+to_string(currNode->right->val)+",";
//                 }
//                 else
//                     ans=ans+"#,";
//         }
        
        
//         return ans;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
        
//         if(data.size()==0)
//             return NULL;
        
//         queue<TreeNode*> q;
        
//         stringstream s(data);
//         string str;
//         getline(s,str,',');
        
//         TreeNode* root=new TreeNode(stoi(str));
//         q.push(root);
        
//         while(!q.empty()){
//             TreeNode* currNode=q.front();
//             q.pop();
//             getline(s,str,',');
//             if(str=="#"){
//                 currNode->left=NULL;
//             }
//             else{
//                 TreeNode* newNode=new TreeNode(stoi(str));
//                 currNode->left=newNode;
//                 q.push(newNode);
//             }
//             getline(s,str,',');
//             if(str=="#"){
//                 currNode->right=NULL;
//             }
//             else{
//                 TreeNode* newNode=new TreeNode(stoi(str));
//                 currNode->right=newNode;
//                 q.push(newNode);
//             }
//         }
//         return root;
//     }
    string serialize(TreeNode* root) {
        string data="";
        if(!root) return data;
        queue<TreeNode*> q;
        q.push(root);
        data+=to_string(root->val)+",";
        while(!q.empty()){
                root=q.front();
                q.pop();
                if(root->left){
                    q.push(root->left); data+=to_string(root->left->val)+",";
                } 
                else data+="#,"; //#-Null
                if(root->right){
                    q.push(root->right); data+=to_string(root->right->val)+",";
                }
                else data+="#,";
        }
        return data;
    }


    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,','); 
        queue<TreeNode*> q;
        if(str=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
                getline(s,str,',');
                if(str=="#") temp->left=NULL;
                else {
                    TreeNode* l=new TreeNode(stoi(str));
                    temp->left=l;
                    q.push(l);
                }
                getline(s,str,',');
                if(str=="#") temp->right=NULL;
                else {
                    TreeNode* r=new TreeNode(stoi(str));
                    temp->right=r;
                    q.push(r);
                }
        }
        
        return root;
       
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

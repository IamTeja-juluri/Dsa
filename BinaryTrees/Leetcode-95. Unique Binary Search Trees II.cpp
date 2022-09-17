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
class Solution {
public:
    vector<TreeNode*> generateTrees(int left, int right){
        if(left>right) return {nullptr};
        vector <TreeNode*> nodes;
        for(int i=left; i<=right; i++){
            vector<TreeNode*> leftNodes=generateTrees(left, i-1);
            vector<TreeNode*> rightNodes=generateTrees(i+1, right);
            for(TreeNode* leftNode:leftNodes){
                for(TreeNode* rightNode: rightNodes){
                    TreeNode* node=new TreeNode(i, leftNode, rightNode);
                    nodes.push_back(node);
                }
            }
        }
        return nodes;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
// JS
 function pathFinder(root,ans,l){

    if(root==null || root==undefined)
        return;

    if(!root.left && !root.right){
        l.push(ans);
        return;
    }
    if(root.left){
        pathFinder(root.left,ans+"->"+root.left.val,l)
    }
    if(root.right){
        pathFinder(root.right,ans+"->"+root.right.val,l)
    }
    return;
 }


var binaryTreePaths = function(root) {
    const l = [];
    if(root==null)
        return l;
    pathFinder(root,root.val.toString(),l);
    return l;
};

// GO
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func pathFinder(root *TreeNode,ans string,result *[]string){
    if root == nil{
        return;
    }
    if root.Left==nil && root.Right==nil{
        *result = append(*result,ans)
        return;
    }
    if root.Left != nil {
        pathFinder(root.Left,ans+"->"+strconv.Itoa(root.Left.Val),result)
    }
    if root.Right != nil {
        pathFinder(root.Right,ans+"->"+strconv.Itoa(root.Right.Val),result)
    }
 }

func binaryTreePaths(root *TreeNode) []string {
   var result [] string
   if root == nil {
        return result
    }
    pathFinder(root,strconv.Itoa(root.Val),&result)
    return result
}

// CPP

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
    vector<string> result;

    void allPathsFinder(TreeNode* root,string ans){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            result.push_back(ans);
            return;
        }
        if(root->left)
           allPathsFinder(root->left,ans+"->"+to_string(root->left->val));
        if(root->right)
            allPathsFinder(root->right,ans+"->"+to_string(root->right->val));   
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return result;
        allPathsFinder(root,to_string(root->val));
        return result;
    }
};


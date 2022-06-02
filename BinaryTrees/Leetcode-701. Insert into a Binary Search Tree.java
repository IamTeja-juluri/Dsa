/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    TreeNode insertNode(TreeNode root,int num){
        
        if(root==null)
            return new TreeNode(num);
        
        
        if(root.val < num)
            root.right=insertNode(root.right,num);
        
        if(root.val > num)
            root.left=insertNode(root.left,num);
           
         return root;
    }
    
    
    public TreeNode insertIntoBST(TreeNode root, int val) {
     
      return insertNode(root,val);    
        
    }
}

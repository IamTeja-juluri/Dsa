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
    
    public TreeNode construct(TreeNode root,int val){
        
        if(root==null)
            return new TreeNode(val);
        
        if(val<root.val)
            root.left=construct(root.left,val);
        
        if(val>root.val)
            root.right=construct(root.right,val);
     
        return root;
    }
    
    public TreeNode bstFromPreorder(int[] preorder) {
        
        
        TreeNode root=null;
        for(int x:preorder)
        root=construct(root,x);
        
        return root;
    }
}

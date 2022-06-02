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
    
    int getMax(int[] nums,int l,int r){
        
        int maxidx=-1;
        int maxval=0;
        
        for(int i=l;i<=r;i++){
            if(maxval<nums[i]){
                maxidx=i;
                maxval=nums[i];
            }
        }
        
        return maxidx;
    }
    
    TreeNode constructTree(int[] nums,int l,int r){
        
        if(l>r)
            return null;
        
        if(l==r)
            return new TreeNode(nums[l]);
        
        int maxidx=getMax(nums,l,r);
        
        TreeNode curr=new TreeNode(nums[maxidx]);
        
        curr.left=constructTree(nums,l,maxidx-1);
        curr.right=constructTree(nums,maxidx+1,r);
        
        return curr;
        
    }
    
    
    
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        
      int l=0;
      int r=nums.length-1;
      
      return constructTree(nums,l,r);  
        
    }
}

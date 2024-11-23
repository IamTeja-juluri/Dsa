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

    void populateNums(TreeNode* root,string val,vector<string>&nums){
        if(!root){
            return;
        }
        populateNums(root->left,val+to_string(root->val),nums);
        populateNums(root->right,val+to_string(root->val),nums);
        if(!root->left && !root->right)
         nums.push_back(val+to_string(root->val));
    }

    int convertBinaryStringsToIntegerAndSum(vector<string>&nums){

        int sum = 0;

        for(auto str:nums){
            int integer = 0;
            int k = 0;
            for(int i=str.size()-1;i>=0;i--){
               int powVal=(str[i]-'0'==1)?pow(2,k):0;
               integer=integer + powVal;
               k+=1;
            }
            sum+=integer;
            
        }

        return sum;
    }

    int sumRootToLeaf(TreeNode* root) {
        if(!root){
            return 0;
        }
        vector<string>nums;
        populateNums(root,"",nums);
        int res = convertBinaryStringsToIntegerAndSum(nums);
        return res;
    }

};

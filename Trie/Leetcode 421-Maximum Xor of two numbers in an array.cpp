class Node{
    
    public:
    
   int data;
   Node* left;
   Node* right;
    
    Node(int d){
        left=NULL;
        right=NULL;
        data=d;
    }
};


class Trie{
    
    public:
    Node* root;
    Trie(){
        root=new Node(100);
    }
    
    void insert(int num){ 
        
        Node* curr=root;
        
        for(int i=30;i>=0;i--){
            
            int val=(num>>i)&1;
            
            if(val==0){
                
                if(!curr->left){
                    
                    curr->left=new Node(val);
                    
                }
                curr=curr->left;
            }
            else{
                
                if(!curr->right){
                    curr->right=new Node(val);
                }
                
                curr=curr->right;
                
            }
        }
        
        
    }
    
    int maxXor(vector<int> nums){
        
        if(nums.size()==0)
            return 0;
        
        int max_xor=0;
        
        for(int j=0;j<nums.size();j++){
            
            Node* curr=root;
             int ans=0;
            
        for(int i=30;i>=0;i--){
            
            int val=(nums[j]>>i)&1;
            
            if(val==0){
                
                if(curr->right){
                   
                    ans=ans+pow(2,i);
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
                
            }
            else{
                
                if(curr->left){
                    
                    ans=ans+pow(2,i);
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            
            
        }
            max_xor=max(max_xor,ans);
        
        
        }
        return max_xor;
        
    }
    
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
    
        Trie t;
    
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }
        
        return t.maxXor(nums);
        
    }
    
};

class Solution {
public:
    
    vector<int> res;
    
    void print_right(Node* root){
        if(root==NULL)
        return;
        if(root->right){
        print_right(root->right);
        res.push_back(root->data);
        }
        else if (root->left){
        print_right(root->left);
        res.push_back(root->data);
       }
    }
    
    void print_left(Node* root){
        if(root==NULL)
        return;
        if(root->left){
        res.push_back(root->data);
        print_left(root->left);
        }
        else if(root->right){
        res.push_back(root->data);
        print_left(root->right);
        }
    }
    
    
    void print_leaves(Node* root){
        if(root==NULL)
        return ;
        if(root->left==NULL and root->right==NULL)
        res.push_back(root->data);
        print_leaves(root->left);
        print_leaves(root->right);
    }

    vector <int> boundary(Node *root)
    {
        if(root==NULL)
        return res;
        res.push_back(root->data);
        print_left(root->left);
        print_leaves(root->left);
        print_leaves(root->right);
        print_right(root->right);
        return res;
    }
};

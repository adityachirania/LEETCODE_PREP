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
    //inorder traversal since it is sorted 
    void find(TreeNode* root,vector<int>& res)
    {
        if(root->left!=NULL)
            find(root->left,res);
        
        res.push_back(root->val);
        
        if(root->right!=NULL)
            find(root->right,res);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        find(root,res);
        return res[k-1];
    }
};

//https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/788/

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
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int ind = 0,int in_start=0,int in_end=0) 
    {
    
        // return NULL if vector is empty
        if(inorder.size()==0)
            return NULL;
    
        
        // only while beginning the funtion call made from main will rely on default values initially and we need to set end as size of vector - 1
        if(ind==0)
        {
            int p;
            p = (int)inorder.size();
            in_end = p-1;
        }
    
        
        // the value to be assigned to current node
        int value = preorder[ind];
        
        // variable that saves index where current value is inorder
        int index;
        for(int i = in_start;i<=in_end;i++)
        {
            if(inorder[i]==value)
            {
                index = i;
                break;
            }
        }
        
        // finding no. of elements in left and right subtrees
        int left_no = index-in_start;
        int right_no = in_end-index;
        
        TreeNode *node;
        // value assigned with the help of the constructor
        node = new TreeNode(value);
    
        
        // repeating same for both subtrees on the left and right
        if(left_no>0)
            node->left = buildTree(preorder,inorder,ind+1,in_start,index-1);
        if(right_no>0)
            node->right = buildTree(preorder,inorder,ind+left_no+1,index+1,in_end);
        
        // return the pointer to subtree's root 
        return node;
           
    }
    
};

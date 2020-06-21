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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        if (root==NULL)return ans ;
        ans.push_back(root->val) ;
        queue<TreeNode*> q ;
        TreeNode* front ;
        q.push(root) ;
        
        // null pointer separates level from each other in the queue
        q.push(NULL) ;
        
        // bfs 
        while(!q.empty()){
            if (q.size()==1)break ;
            front = q.front() ;
            if (front==NULL){
                q.pop() ;
                q.push(NULL) ;
                ans.push_back(q.front()->val) ;
            }
            else{
                q.pop() ;
                if (front->right!=NULL)q.push(front->right) ;
                if (front->left!=NULL)q.push(front->left) ;
            }
        }
        return ans ;
    }
};

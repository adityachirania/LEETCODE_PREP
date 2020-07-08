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
    vector<TreeNode*> dp[21];
    
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ans;
        if(N%2==0)return dp[N] = ans;
        
        if(N==1)
        {
            TreeNode* root;
            root = new TreeNode;
            ans.push_back(root);
            return ans;
        }
        
        for(int i = 1;i <=N-2;i+=2)
        {
            int leftnum = i;
            int rightnum = N - i - 1;
            
            vector<TreeNode*> leftside,rightside;
            
            if(dp[leftnum].size()!=0)leftside = dp[leftnum];
            else
                leftside = allPossibleFBT(leftnum);
            if(dp[rightnum].size()!=0)rightside = dp[rightnum];
            else
                rightside = allPossibleFBT(rightnum);
            
            for(int i = 0;i<leftside.size();i++)
            {
                for(int j =  0; j < rightside.size();j++)
                {
                    TreeNode* root;
                    root = new TreeNode;
                    root->left = leftside[i];
                    root->right = rightside[j];
                    ans.push_back(root);
                }
            }
            
        }
        
        return dp[N] = ans;
        
    }
};

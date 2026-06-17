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
    int sum(TreeNode* root,int& maxsum){
        if(root==NULL)return 0;

        int lhsum=sum(root->left,maxsum)+root->val;
        int rhsum=sum(root->right,maxsum)+root->val;

        maxsum=max(root->val,max(max(lhsum,rhsum),max(lhsum+rhsum-root->val,maxsum)));
        return max(root->val, max(lhsum, rhsum));    
        }

    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int dum=sum(root,maxsum);
        return maxsum;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        int sign=0;
        
        while(!q.empty()){
            int n=q.size();
            vector<int> res;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                res.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(sign==1){
                reverse(res.begin(),res.end());
                ans.push_back(res);
                sign=0;
            }
            else{
                ans.push_back(res);
                sign=1;
            }
        }
        return ans;
    }
};

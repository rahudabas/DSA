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
    void inkro(TreeNode* root,int val,TreeNode* prev,int& cnt){
        if(root==NULL){
            if(cnt==1){
                TreeNode* newi=new TreeNode(val);
                prev->left=newi;
                return;
            }
            else{
                TreeNode* newi=new TreeNode(val);
                prev->right=newi;  
                return;          
            }
        }
        if(val>root->val){
            prev=root;
            cnt=0;
            inkro(root->right,val,prev,cnt);
        }
        else if(val<root->val){
            prev=root;
            cnt=1;
            inkro(root->left,val,prev,cnt);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
            
        int cnt;
        TreeNode* prev;
        inkro(root,val,prev,cnt);
        return root;
    }
};

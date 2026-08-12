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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<int,int,TreeNode*>> q;
        if(root==NULL)return {};
        priority_queue< 
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
            > pq;
        q.push({0,0,root});
        while(!q.empty()){
            auto [c,r,st] = q.front();
            q.pop();

            if(st->left)q.push({c-1,r+1,st->left});
            if(st->right)q.push({c+1,r+1,st->right});
            pq.push({c,r,st->val});
        }

        vector<vector<int>> ans;
        vector<int> tmp;
        int prev=INT_MIN;
        while(!pq.empty()){
            auto[c,r,x] = pq.top();
            pq.pop();
            if(c!=prev){
                if(!tmp.empty()){
                    ans.push_back(tmp);
                }
                tmp.clear();
                prev=c;
                tmp.push_back(x);
            }
            else{
                tmp.push_back(x);
            }
        }
        if(!tmp.empty()){
            ans.push_back(tmp);
        }
        return ans;
    }
};

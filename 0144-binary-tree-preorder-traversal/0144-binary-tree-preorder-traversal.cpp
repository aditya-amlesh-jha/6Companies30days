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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        stack<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        vector<int> ans;
        while(pendingNodes.size()){
            TreeNode *top = pendingNodes.top();
            pendingNodes.pop();
            ans.push_back(top->val);
            if(top->right){
                pendingNodes.push(top->right);
            }
            if(top->left){
                pendingNodes.push(top->left);
            }
        }
        return ans;
    }
};
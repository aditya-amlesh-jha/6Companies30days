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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> map;
        traverse(root,map);
        vector<TreeNode*> ans;
        for(auto [x,y]:map){
            if(y.size() > 1){
                ans.push_back(y[0]);
            }
        }
        return ans;
    }
    string traverse(TreeNode *root, unordered_map<string,vector<TreeNode*>> &map){
        if(root == nullptr){
            return "";
        }
        string s ="("+traverse(root->left,map)+to_string(root->val)+traverse(root->right,map)+")";
        map[s].push_back(root);
        return s;
    }
};
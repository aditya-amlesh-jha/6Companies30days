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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inOrder(root1,a);
        inOrder(root2,b);
        vector<int> c;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                c.push_back(a[i++]);
            }
            else{
                c.push_back(b[j++]);
            }
        }
        while(i<a.size()){
            c.push_back(a[i++]);
        }
        while(j<b.size()){
            c.push_back(b[j++]);
        }
        return c;
    }
    void inOrder(TreeNode *root, vector<int> &ans){
        if(root==nullptr){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
};
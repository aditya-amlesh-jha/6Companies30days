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
        vector<int> ans;
        stack<TreeNode*> a,b;
        //combining iterative inorder for two trees;
        while(a.size() || b.size() || root1 || root2){
            while(root1){
                a.push(root1);
                root1=root1->left;
            }
            while(root2){
                b.push(root2);
                root2=root2->left;
            }
            //now take stack top with lesser value
            //case : one stack can be empty
            // TreeNode *top;
            if(b.empty() || (a.size() && a.top()->val<=b.top()->val)){
                root1 = a.top();
                a.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
            else{
                root2 = b.top();
                b.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }     
        }
        return ans;
    }
};
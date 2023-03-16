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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        int index = inorder.size()-1;
        return buildTree(map,postorder,0,index,index);
    }
    TreeNode* buildTree(unordered_map<int,int> &map, vector<int>& postorder, int left, int right, int &index) {
        if(left > right){
            return nullptr;
        }
        TreeNode *newNode = new TreeNode(postorder[index]);
        int rootIndex = map[postorder[index--]];
        newNode->right = buildTree(map,postorder,rootIndex+1,right,index);
        newNode->left = buildTree(map,postorder,left,rootIndex-1,index);
        
        return newNode;
    }
};
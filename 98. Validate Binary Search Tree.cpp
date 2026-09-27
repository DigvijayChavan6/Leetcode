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
    long prev = numeric_limits<long>::min();
    bool answer = true;
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            if(prev >= root->val){
                answer = false;
            }
            prev = root->val;
            inorder(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return answer;
    }
};
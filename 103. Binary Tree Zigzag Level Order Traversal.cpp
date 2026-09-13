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
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        bool flag = false;

        if(root == NULL)return levels;
        q.push(root);
    
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            if(flag){
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            levels.push_back(level);
        }

        return levels;
    }
};
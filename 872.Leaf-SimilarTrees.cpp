// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true
// Example 2:


// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
 

// Constraints:

// The number of nodes in each tree will be in the range [1, 200].
// Both of the given trees will have values in the range [0, 200].

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
    bool re=true;
    vector<int> vec;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaf(root1);
        chLeaf(root2);
        if(vec.size()!=0)return false;
        return re;
    }
    void getLeaf(TreeNode *p){
        if(p!=NULL){
            getLeaf(p->left);
            if(p->left==p->right)vec.push_back(p->val);
            getLeaf(p->right);
        }
    }
    void chLeaf(TreeNode *p){
        if(p!=NULL){
            chLeaf(p->left);
            if(p->left==p->right){
                if(vec.size()==0){
                    re=false;
                    return;
                }
                if(vec[0]!=p->val)re=false;
                vec.erase(vec.begin());
            }
            chLeaf(p->right);
        }
    }
};
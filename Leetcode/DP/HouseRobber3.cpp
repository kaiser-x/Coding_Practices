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
    private:
    //with recursion
    //     int helper(TreeNode *root){
    //     if(root==NULL) return 0;
    //     int pick=root->val;
    //     if(root->left!=NULL) pick+=helper(root->left->left)+helper(root->left->right);
    //     if(root->right!=NULL) pick+=helper(root->right->right)+helper(root->right->left);
    //     int notpick=helper(root->left)+helper(root->right);
    //     return max(pick,notpick);
    // }
    //with memo
    unordered_map<TreeNode*,int>dp;
    int helper(TreeNode *root){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int pick=root->val;
        if(root->left!=NULL) pick+=helper(root->left->left)+helper(root->left->right);
        if(root->right!=NULL) pick+=helper(root->right->right)+helper(root->right->left);
        int notpick=helper(root->left)+helper(root->right);
        return dp[root]=max(pick,notpick);
    }
public:
    int rob(TreeNode* root) {
        return helper(root);
    }
};
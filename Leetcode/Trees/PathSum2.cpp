// 113. Path Sum II
// Given the root of a binary tree
// and an integer targetSum, return
// all root-to-leaf paths where the 
// sum of the node values in the path
// equals targetSum. Each path should
// be returned as a list of the node 
// values, not node references.

// A root-to-leaf path is a path starting 
// from the root and ending at any leaf node. 
// A leaf is a node with no children.

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
    vector<vector<int>>res;
    void pathsum(TreeNode* root,int target,int sum,vector<int>&path){
        if(root==NULL) return;
        path.push_back(root->val);
        sum+=root->val;
        if(sum==target&&root->left==NULL&&root->right==NULL){
            res.push_back(path);
        }
        if(root->left!=NULL) pathsum(root->left,target,sum,path);
        if(root->right!=NULL) pathsum(root->right,target,sum,path);
        sum-=root->val;
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pathsum(root,targetSum,0,path);
        return res;
    }
};
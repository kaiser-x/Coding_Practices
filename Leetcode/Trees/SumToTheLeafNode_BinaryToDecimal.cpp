// 1022. Sum of Root To Leaf Binary Numbers

// You are given the root of a binary tree where each
//  node has a value 0 or 1. Each root-to-leaf path
//   represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1,
//  then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers
//  represented by the path from the root to that leaf.
//   Return the sum of these numbers.
// Input: root = [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
class Solution {
public:
    void helper(TreeNode* root,int &totalSum,int leafSum){
        if(root==NULL) return; 
        leafSum=leafSum*2;
        leafSum+=root->val;
        if(root->left==NULL&&root->right==NULL) {totalSum+=leafSum;}
        if(root->left!=NULL) helper(root->left,totalSum,leafSum);
        if(root->right!=NULL) helper(root->right,totalSum,leafSum);    
        //without this will also work 
        // leafSum-=root->val;
        // leafSum=leafSum/2;
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        helper(root,sum,0);
        return sum;
    }
};
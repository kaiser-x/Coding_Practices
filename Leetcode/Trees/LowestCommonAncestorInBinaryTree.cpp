// 236. Lowest Common Ancestor of a Binary Tree
// Medium
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
// between two nodes p and q as the lowest node in T that has both p and q as descendants 
// (where we allow a node to be a descendant of itself).”
// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of 
// itself according to the LCA definition.
// Example 3:
// Input: root = [1,2], p = 1, q = 2
// Output: 1
// Constraints:
// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the tree.

//CPP Code:

class Solution {
public:
    /*The intuition is to make a dfs call,so as we make the call we check if the current node is p or q, if it is 
    then we return that node itself,if it is null then we return null,now make the left and right dfs call,
    then we check if the left and right are null, that mean neither the current node nor its left and right subtree
    contains either of p and q, so we return null from the current node, else if left is not null and right is null
    , tha means left subtree has either of p and q in it,vice versam right not null and left is null, then right
    subtree has either of p and q in it,in both case we return the not null side, now if the current node has
    both right and left as not null, that mean the left and right subtree contain the p and q node,so as we made
    dfs call, the current node is the lowest common ancestor,so we return that current node itself.*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if we reached null means return null,bcs we found no node to be equal to either of p and q;
        if(root==nullptr) return nullptr;
        //if node is equal to p,then  return that node itself
        if(root==p) return root;
        //similary for q
        if(root==q) return root;
        //now we make the left and right dfs call
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        //Now we check if both the left and right is null then return null
        if(left==nullptr&&right==nullptr) return nullptr;
        //now we check if either of them is not null and the other one is null
        else if(left!=nullptr&&right==nullptr) return left;
        else if(left==nullptr&&right!=nullptr) return right;
        //Now if both of them is not null, then we found our LCA so we return that node itself
        //if(left!=nullptr&&right!=nullptr) return root;
        else return root;
        
        /*We can refractor the above approach */
        
        //we can include the based condtion in single if
        if(root==nullptr||root==p||root==q) return root;
        //Same left and right call
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        //Now what we can do is have three if else if, instead of three 4if's.
        if(left==nullptr) return right;
        /*The above will take care of case where both left and right are null, how?? bcs any how we have to return
        null right, if left is null and then we return right, which is also null then we are inturn return null
        gott it?,or on the other hand if the left is null and the right is not null,in that case we haave to return
        right ,so that is also handled in here*/
        
        /*Similary we can have an else if, we will reach this else if only when left is not null,so we check if
        rightis null, so what we do if left is not null and right is null we return left*/
        else if(right==nullptr) return left;
        /*now the last part which we will reach only if left and right both are not null,what we do in that case?
        as if left and right are not null, that ,means the current node is the LCA so we return that node itself*/
        else return root;
        
    }
};

//Java Code:

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null) return null;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode left=lowestCommonAncestor(root.left,p,q);
        TreeNode right=lowestCommonAncestor(root.right,p,q);
        if(left==null&&right==null) return null;
        else if(left!=null&&right==null) return left;
        else if(right!=null&&left==null) return right;
        else return root;
        //refractored
        if(root==null||root==p||root==q) return root;
        TreeNode left=lowestCommonAncestor(root.left,p,q);
        TreeNode right=lowestCommonAncestor(root.right,p,q);
        if(left==null) return right;
        else if(right==null) return left;
        else return root;
        
    }
}
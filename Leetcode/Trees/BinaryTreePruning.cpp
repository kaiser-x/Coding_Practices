// 814. Binary Tree Pruning
// Medium
// Given the root of a binary tree, return the same tree where every subtree 
// (of the given tree) not containing a 1 has been removed.
// A subtree of a node node is node plus every node that is a descendant of node.
// Example 1:
// Input: root = [1,null,0,0,1]
// Output: [1,null,0,null,1]
// Explanation: 
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
// Example 2:
// Input: root = [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
// Example 3:
// Input: root = [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]
// Constraints:
// The number of nodes in the tree is in the range [1, 200].
// Node.val is either 0 or 1.

class Solution {
public:
    bool dfs(TreeNode* root){
        if(root==nullptr) return false;
        bool lh=dfs(root->left);
        if(lh==false) root->left=nullptr;
        bool rh=dfs(root->right);
        if(rh==false) root->right=nullptr;
        return (root->val==1)|| lh||rh;
    }
    TreeNode* dfsR(TreeNode* root){
        if(root==NULL) return NULL;
        //this will not work bc we are not updating the left and right value with dfs call,we are just 
        //calling it.
        //what will happen here is the dfs call is made to root that 1 is , then 1 is not null, then
        //the if checkes if 1 value is 0, its not, as it is a && operation due to lazy cheking
        //as soon as the first cond fails control moves to next line and it return node 1 thats root.
        // if(root->val==0&&dfsR(root->left)==NULL&&dfsR(root->right)==NULL) root=nullptr;
        //instead this is what we need to do
        root->left=dfsR(root->left);
        root->right=dfsR(root->right);
        if(root->val==0&&root->left==NULL&&root->right==NULL) root=NULL;
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        //this first one using boolena dfs my intutioon was a node will return true if that node is 1 or it
        //has one in its left subtree or one in its right subtree, and if any of its left or right subtree
        //return false then we change it to null, so a node will be saved if any of its the three options 
        //is true, and if we hit null then we retutn false bcs all three conditions will be false for them
        //then the leaf nodes which are 0 will be deleted then upper 0;s if any will aslo be delted if it 
        //doesnt have 1 its other child subtree.
        // bool f=dfs(root);
        // if(f==false) root=nullptr;
        //we can also do it using regular bfs, the condition is also intutive,we travers till leaf node and 
        //start deleteing from here, bcs if a leaf node is 0 it has to be delted and we will delete by 
        //assigning null to it, we will delte if the node has 0 as value and it's left and right child
        //are null.
        root=dfsR(root);
        return root;
    }
};

class Solution {
    public static boolean dfs(TreeNode root){
        if(root==null) return false;
        boolean flag=false;
        if(root.val==1) flag=true;
        boolean lh=dfs(root.left);
        boolean rh=dfs(root.right);
        if(lh==false) root.left=null;
        if(rh==false) root.right=null;
        return flag||lh||rh;
    }
    public TreeNode pruneTree(TreeNode root) {
        boolean f=dfs(root);
        if(f==false) root=null;
        return root;
    }
}
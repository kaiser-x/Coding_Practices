// 124. Binary Tree Maximum Path Sum
// Hard
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the 
// sequence has an edge connecting them. A node can only appear in the sequence at most once. 
// Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.
// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

//CPP
class Solution {
public:
    /*the approach is foundation on finding height of a BT, now the path summ cam be any path, it's
    not like the path sum question where need to find target sum from root to leaf, here the path can
    pass through root node or it cannot,so what we are doing, the main idea is if we are standing at
    a node, then when we return to the previous dfs call, we will return the maximum path sum,what will
    be the maximum path sum,= root->val+ max(leftsum,rightsum),and next, we considre each node to be 
    the curve point in the path, imagine path going like a upside down U, and the curve point to be
    that current node, so we now have the maximum path sum from left, and we have maximum path sum from
    right and the root val, so we add all three and check if it is max,i.e, 
    mx=max(mx,(root->val+leftSum+rightSum)), why do we doo this have a second variable, bcs if we 
    directly return root->val+ max(leftsum,rightsum),then we are choosing from left and right,but that
    is not what we want, we want to include the max from left and right and root val to find the 
    maximum path sum wrt the node as curve point,So, at each node we have to find the maximum path sum
    wrt to curr node as curve point, but to get that max leftSum or max rightSum, we need to choose
    b/w left or right ,whichever gives max value when added with curr root val, will be sent to the 
    prev dfs call,this is the reason why we need to have a variable passed with reference in dfs call
    ,Now if any of the leftSum or right sum return negative value, then we will have to ignore,bcs
    they will only reduce the maximum path value, we ignore those nodes, bcs the path doesnt have to
    pass through root or leaf nodes, it just need to be path, imagine a tree 2,-1,null, if we 
    consider the max leftSum of -1, then 2-1 will become 1, but the answer will be single node 2.*/
    int dfs(TreeNode* root,int &mx){
        if(root==nullptr) return 0;
        int value=root->val;
        int lh=dfs(root->left,mx);
        int rh=dfs(root->right,mx);
        //If we are having negative paths in any two child paths, then we have to ignore them
        //inorder to get maximum path sum, bc if we consider those negative paths ,itll just hinder
        //our job at finding max path sum as the max sum will be reduced.
        lh=(lh<0)? 0:lh;
        rh=(rh<0)? 0:rh;
        mx=max(mx,value+(lh+rh));
        return value+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        dfs(root,mx);
        return mx;
    }
};

//Java

class Solution {
    public int dfs(TreeNode root,int arr[]){
        if(root==null) return 0;
        int value=root.val;
        int lh=dfs(root.left,arr);
        int rh=dfs(root.right,arr);
        lh=(lh<0)?0:lh;
        rh=(rh<0)?0:rh;
        arr[0]=Math.max(arr[0],value+lh+rh);
        return value+Math.max(lh,rh);
    }
    public int maxPathSum(TreeNode root) {
        int arr[]={Integer.MIN_VALUE};
        dfs(root,arr);
        return arr[0];
    }
}
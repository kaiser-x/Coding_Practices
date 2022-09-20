// 543. Diameter of Binary Tree
// Easy
// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes 
// in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.
// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:
// Input: root = [1,2]
// Output: 1
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100

class Solution {
public:
    /*The foundation is take from height or depth of BT, in that for each node we find it's left 
    subtree and right subtree height, and return the maximum of them left and right added with 1(to
    return the height included with the current node to its prev recursive call),so we are gonna
    make use of this funtion, we can addtionally have a maxi variable that stores the ,max left 
    height+ max right height or current maxi,why we are not including 1 this time unlike while finding
    the height, bcs there height is based on nodes, so if there's a skew tree with 3 nodes, then the
    height will be three,but diameter will be 2 (calculated from 2nd node), diameter is number of 
    edges,so thats the reason why we dont include or add 1 to lh+rh while calculating maxi,so at each
    node we consider it has the curve point in the path thats gonna act like diameter of the tree,
    we take left height, we take right height, then check if the current node will give maxi, then
    we return the max of left and right height +1,bcs we need to select only the path which will have
    greater number of nodes.*/
    int dfs(TreeNode *root,int &mx){
        if(root==nullptr) return 0;
        int lh=dfs(root->left,mx);
        int rh=dfs(root->right,mx);
        mx=max(mx,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx=INT_MIN;
        dfs(root,mx);
        return mx;
    }
};
//java

class Solution {
    int dfs(TreeNode root,int arr[]){
        if(root==null) return 0;
        int lh=dfs(root.left,arr);
        int rh=dfs(root.right,arr);
        arr[0]=Math.max(arr[0],lh+rh);
        return Math.max(lh,rh)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int arr[]={Integer.MIN_VALUE};
        dfs(root,arr);
        return arr[0];
    }
}
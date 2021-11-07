// 101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return false;
        if(root.left==null&&root.right==null) return true;
        return isMirror(root.left,root.right);
    }
    public static boolean isMirror(TreeNode p,TreeNode q){
        if(p==null||q==null)
            return p==q;
        return (p.val==q.val)&&isMirror(p.left,q.right)&&isMirror(p.right,q.left);
    }
}
 
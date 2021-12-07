class Solution {
    public static int check(TreeNode node){
        if(node==null) return 0;
        int lh=check(node.left);
        int rh=check(node.right);
        if(lh==-1||rh==-1) return -1;
        if(Math.abs(lh-rh)>1) return -1;
        return Math.max(lh,rh)+1;
    }
    public boolean isBalanced(TreeNode root) {
        if(check(root)==-1) return false;
        return true;
    }
}
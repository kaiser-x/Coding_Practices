// 559. Maximum Depth of N-ary Tree

// Given a n-ary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down
//  to the farthest leaf node.
class Solution {
    public int maxDepth(Node root) {
        if(root==null) return 0;
        int mx=0;
        if(root.children!=null){
            for(int i=0;i<root.children.size();i++){
                mx=Math.max(mx,maxDepth(root.children.get(i)));
            }
        }
        return 1+mx;
    }
}
// 94. Binary Tree Inorder Traversal

// Given the root of a binary tree, 
// return the inorder traversal of its nodes' values.

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode>st=new Stack<>();
        TreeNode node=root;
        List<Integer>res=new ArrayList<>();
        while(true){
            if(node!=null){
                st.add(node);
                node=node.left;
            }else{
                if(st.isEmpty()) break;
                node=st.pop();
                res.add(node.val);
                node=node.right;
            }
        }
        return res;
    }
}
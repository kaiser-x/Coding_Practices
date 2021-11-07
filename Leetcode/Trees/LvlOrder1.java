102. Binary Tree Level Order Traversal

// Given the root of a binary tree, return the level order traversal of its nodes' values.
//  (i.e., from left to right, level by level).

 class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>res=new ArrayList<List<Integer>>();
        if(root==null)
           return  res;
        Queue<TreeNode>q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            List<Integer>al=new ArrayList<>();
            for(int i=0;i<size;i++){
                TreeNode node=q.poll();
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
                al.add(node.val);
            }
            res.add(al);
        }
        return res;
    }
}
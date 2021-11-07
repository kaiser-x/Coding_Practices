// 589. N-ary Tree Preorder Traversal
// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

class Solution {
    List<Integer>res=new ArrayList<>();
    public List<Integer> preorder(Node root) {
        helper(root);
        return res;
    }
    public void helper(Node node){
        if(node==null) return;
        res.add(node.val);
        for(int i=0;i<node.children.size();i++)
                helper(node.children.get(i));
    }
}
// 590. N-ary Tree Postorder Traversal
// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. 
// Each group of children is separated by the null value (See examples)

class Solution {
    List<Integer>res=new ArrayList<>();
    public List<Integer> postorder(Node root) {
        helper(root);
        return res;
    }
    public void helper(Node node){
        if(node==null) return ;
        for(int i=0;i<node.children.size();i++){
            helper(node.children.get(i));
        }
        res.add(node.val);
    }
}
// 429. N-ary Tree Level Order Traversal

// Given an n-ary tree, return the level order traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal, 
// each group of children is separated by the null value (See examples).

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>>res=new ArrayList<List<Integer>>();
        if(root==null) return res;
        Queue<Node>q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            List<Integer>al=new ArrayList<Integer>();
            for(int i=0;i<size;i++){
                Node node=q.poll();
                for(int j=0;j<node.children.size();j++){
                    if(node.children.get(j)!=null) q.add(node.children.get(j));
                }
                al.add(node.val);
            }
            res.add(al);
        }
       return res;
    }
}
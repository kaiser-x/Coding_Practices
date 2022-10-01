// 863. All Nodes Distance K in Binary Tree
// Medium
// Given the root of a binary tree, the value of a target node target, and an integer k, 
// return an array of the values of all nodes that have a distance k from the target node.
// You can return the answer in any order.
// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) 
// have values 7, 4, and 1.
// Example 2:
// Input: root = [1], target = 1, k = 3
// Output: []
// Constraints:
// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000

//CPP Code:

class Solution {
public:
    /*So if you observe carefully youll find that for each node we can find the nodes at distance k under it i.e 
    the desecendants of the current node at a distance of k, but we can not get the nodes at distance K that
    passes through the parent nodes of the current node, so we have left and right pointers to travel to
    the child,so if we can have the parent pointer too then we can travel that parent path too. So we gona have a map
    that stores the parent of each node,we gonna use level order to obtain the parent pointers,then we can do 
    level order traversal again starting from the given Target node, so usually target node i.e the pointer to the
    target node is give, but sometimes we are given just the value,so we can find the node using the value then
    proceed, so while doing lvl oder traversal we need to check if the node is alredy visited or not to avoid
    infinite loop and TLE, how it'll occur?? imagine you at a node, you got to its left child, then in left child
    you go to it's parent node,now this node is already visited ,and it'll create a inifinite loop,so we can
    make use of a set ot check visited nodes, then we can have a distance value,if the distance becomes equal to k 
    then we add it to the result array. and at end retrun array;*/
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr) return {};
        unordered_map<TreeNode*,TreeNode*> parents;
        parents[root]=nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* ele=q.front();q.pop();
                if(ele->left!=nullptr) {
                    parents[ele->left]=ele;
                    q.push(ele->left);
                }
                if(ele->right!=nullptr){
                    parents[ele->right]=ele;
                    q.push(ele->right);
                }
            }
        }
        vector<int> res;
        unordered_set<TreeNode*> vis;
        queue<pair<TreeNode*,int>> qe;
        qe.push({target,0});
        vis.insert(target);
        while(!qe.empty()){
            int size=qe.size();
            for(int i=0;i<size;i++){
                TreeNode *ele=qe.front().first;
                int dis=qe.front().second;qe.pop();
                if(dis==k) res.push_back(ele->val);
                vis.insert(ele);
                if(ele->left!=NULL&&vis.count(ele->left)==0) qe.push({ele->left,dis+1});
                if(ele->right!=NULL&&vis.count(ele->right)==0) qe.push({ele->right,dis+1});
                if(parents[ele]!=NULL&&vis.count(parents[ele])==0) qe.push({parents[ele],dis+1});
            }
        }
        return res;
        
        /*Now the above approach is okay, but you can see tha twe are still traveling even after hitting the distance
        k,we are traversing the whole tree, lets understand why we are doing level odre traversal, it is bcs we are
        taking the two childs and the parent as the nodes in next lvl of the current lvl, the left and right childs
        and the parent nodes makes are included into a new lvl, and we can observe that all the nodes that are K
        distance from target node ar thoses which are the nodes present at level K from the target nodes level 0,
        so what we can do is once we reach the lvl K, we can break out,and all the nodes present the queue at
        that time will be nodes at distan K from the target node.*/
        vector<int> res;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> qe;
        qe.push(target);
        int dis=0;
        while(!qe.empty()){
            if(dis==k) break;
            int size=qe.size();
            for(int i=0;i<size;i++){
                TreeNode *ele=qe.front();qe.pop();
                vis.insert(ele);
                if(ele->left!=NULL&&vis.count(ele->left)==0) qe.push(ele->left);
                if(ele->right!=NULL&&vis.count(ele->right)==0) qe.push(ele->right);
                if(parents[ele]!=NULL&&vis.count(parents[ele])==0) qe.push(parents[ele]);
            }
            dis++;
        }
        while(!qe.empty()){
            res.push_back(qe.front()->val);qe.pop();
        }
            return res;
    }
};

//Java 

class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        if(root==null) return new ArrayList<Integer>();
        Queue<TreeNode> q=new LinkedList<>();
        HashSet<TreeNode> vis=new HashSet<>();
        HashMap<TreeNode,TreeNode> parents=new HashMap<>();
        parents.put(root,null);
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode ele=q.poll();
                if(ele.left!=null){
                    parents.put(ele.left,ele);
                    q.add(ele.left);
                }
                if(ele.right!=null){
                    parents.put(ele.right,ele);
                    q.add(ele.right);
                }
            }
        }
        q.add(target);
        int dis=0;
        while(!q.isEmpty()){
            if(dis==k) break;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode ele=q.poll();
                vis.add(ele);
                if(ele.left!=null&&!vis.contains(ele.left)) q.add(ele.left);
                if(ele.right!=null&&!vis.contains(ele.right)) q.add(ele.right);
                if(parents.get(ele)!=null&&!vis.contains(parents.get(ele))) q.add(parents.get(ele));
            }
            dis++;
        }
        List<Integer> al=new ArrayList<Integer>();
        while(!q.isEmpty()){
            al.add(q.poll().val);
        }
        return al;
    }
}
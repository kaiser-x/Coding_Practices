// 662. Maximum Width of Binary Tree
// Medium
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes 
// (the leftmost and rightmost non-null nodes), where the null nodes between the 
// end-nodes that would be present in a complete binary tree extending down to that 
// level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.
// Example 1:
// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
// Example 2:
// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 
// (6,null,null,null,null,null,7).
// Example 3:
// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).
// Constraints:
// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100


//CPP Code:
/*So let me first explain the question, the maximum width is the distance between two nodes at the extreme left and
extreme right at the same level (stress on same level for example if the left node is at HD of -3 and lvl3, now there
is a node at lvl 2 with HD of let's say 3,and a node at lvl 3 with HD of 2, then we can consider the node at lvl 2
just bcs it'll give max width, we have to consider the node at the same lvl at 3),So the idea is to index all the 
nodes in tree strating from 0 or 1, then at each node we can just subtract last node and first node at a level
to get the width of that lvl, then we can caculate the max like this, so using segemnt tree concept, if the start
-ing is from 0, then a node with index i, will have left child as (2*i+1) and right child as (2*i+2),and those
which start indexing from 1, the node with index i will have left child as (2*i) and right child as (2*i+1),
so we are gonna do the level order traversal, the queue will have a pair of treenode* and int, treenode* for the
node and int for the index, or we can change the value of the node itself but changing input data is not advisable
in a interview and stuff, so yeah as we traverse the tree in BFS manner, we get the min index and max index from
a level, then we start the for loop to add the children of nodes in that lvl,while adding the children of a node
we get the corresponding index of that node then if left child present add a pair of left child and 
(2*curr_node_index[i.e i]), similarly for right if rightchild present add pair of right child and
(2*curr_node_index)+1, we are following one based indexing. and after for loop ends, we check if the width is max
or not using the mind_ind and max_ind that we got earlier, min_ind will be queue front and max index will be queue
back, then return that max width after completely traversing.*/
class Solution {
public:
    /*The above disscussed approach will obviously throw TLE,why?? imagine a skew tree, we are doing 2*i for
    every node,so at a point int can hold the 2*i value,so it'll throw TLE.*/
    //72/114 test cases.
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int mx=INT_MIN;
        while(!q.empty()){
            int min_ind=q.front().second,max_ind=q.back().second;
            int size=q.size();
            for(int c=0;c<size;c++){
                TreeNode* ele=q.front().first;
                int i=q.front().second;
                q.pop();
                if(ele->left!=nullptr) q.push({ele->left,(2*i)});
                if(ele->right!=nullptr) q.push({ele->right,(2*i)+1});
            }
            mx=max(mx,(max_ind-min_ind )+1);
        }
        return mx;
    /* So to stop getting TLE what can we do? so instead of index each node 1,2.. starting from root, why don't we
    index each node at a level from 0,1,2.. so on, so at each level the first node will have index 1 and last node
    will have corresponding index,in this way we try to avoid the TLE, but how to do it? it's simple so what
    we can do is take the min index in each level then while doing for loop and adding child to queue, subtract
    the curr_node_index with that min index and then push the 2*curr_index and 2*curr_ind+1,what it'll do is
    for 1 based indexing it'll give left child as 0 and right child as 1,then subsequently all levels except root
    level will start from 0, for 1 based index the left child is 2*curr_ind+1 and right is 2*curr_ind+2,so all
    lvls will start with index as 1 except root lvl which will have 0 indexed root node.*/
        //tle
        //112/114 testcases passed
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int mx=INT_MIN;
        while(!q.empty()){
            int min_ind=q.front().second,max_ind=q.back().second;
            int size=q.size();
            for(int c=0;c<size;c++){
                TreeNode* ele=q.front().first;
                int i=q.front().second-min_ind;
                q.pop();
                if(ele->left!=nullptr) q.push({ele->left,(2*i)});
                if(ele->right!=nullptr) q.push({ele->right,(2*i)+1});
            }
            mx=max(mx,(max_ind-min_ind )+1);
        }
        return mx;
        /*Normal the above approach will be sufficient but there are two cases that are failing, so instead of
         int we can use long long, or as we are not dealing with negative numbersers we ca use unsigned int,
         or long long unsigned int*/
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,unsigned int>> q;
        /*If you have 1 based indexing then the first root lvl will have starting index as 1 ,rest all will
        have starting index as 0,now if we have 0 based indxing then only the first root lvl will have starting
        index as 0 rest all lvl will have starting index as 1,so for 1 based indexing as 0 is min in all lvl instead
        of subtracting each node index with min_ind before adding their child ,can we subtract it with 0? yes you
        can, but will need to handle the edge case where root lvl has min_ind as 1,so 1-0 will do nothing,if 
        you don't then it'll just become like normal traversing the first approach*/
        q.push({root,1});
        unsigned int mx=0;
        while(!q.empty()){
            unsigned int min_ind=q.front().second,max_ind=q.back().second;
            int size=q.size();
            for(int c=0;c<size;c++){
                TreeNode* ele=q.front().first;
                unsigned int i=q.front().second-min_ind;
                // cout<<min_ind<<": ";
                // cout<<i<<"; ";
                q.pop();
                if(ele->left!=nullptr) q.push({ele->left,(2*i)});
                if(ele->right!=nullptr) q.push({ele->right,(2*i)+1});
            }
            mx=max(mx,(max_ind-min_ind )+1);
        }
        return mx;
    }
};

//Java Code:

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        Queue<Pair<TreeNode,Integer>> q=new LinkedList<>();
        q.add(new Pair(root,1));
        int mx=0;
        while(!q.isEmpty()){
            int size=q.size();
            int min_ind=q.peek().getValue(),max_ind=0;
            for(int c=0;c<size;c++){
                TreeNode ele=q.peek().getKey();
                int i=q.peek().getValue();
                q.poll();
                if(c==size-1) max_ind=i;
                if(ele.left!=null) q.add(new Pair(ele.left,2*i));
                if(ele.right!=null) q.add(new Pair(ele.right,2*i+1));
            }
            mx=Math.max(mx,(max_ind-min_ind)+1);
        }
        return mx;
        //Second approach
         if(root==null) return 0;
        Queue<Pair<TreeNode,Integer>> q=new LinkedList<>();
        q.add(new Pair(root,1));
        int mx=0;
        while(!q.isEmpty()){
            int size=q.size();
            int min_ind=q.peek().getValue(),max_ind=0;
            for(int c=0;c<size;c++){
                TreeNode ele=q.peek().getKey();
                int i=q.peek().getValue()-min_ind;
                q.poll();
                if(c==size-1) max_ind=i;
                if(ele.left!=null) q.add(new Pair(ele.left,2*i));
                if(ele.right!=null) q.add(new Pair(ele.right,2*i+1));
            }
            mx=Math.max(mx,(max_ind-min_ind)+1);
        }
        return mx;
        //3rd approach
        //The queue in java doesn't have q.back() like in cpp, so to find it we can make use of the for loop used
        //to add children nodes, so if c==size-1, them that node's index is the max_ind ,so store it.
        if(root==null) return 0;
        Queue<Pair<TreeNode,Long>> q=new LinkedList<>();
        q.add(new Pair(root,1L));
        Long mx=0L;
        while(!q.isEmpty()){
            int size=q.size();
            Long min_ind=q.peek().getValue(),max_ind=0L;
            for(int c=0;c<size;c++){
                TreeNode ele=q.peek().getKey();
                //we can explicitly find the min_indin the for loop, or we can just initialise it at start of each 
                //lvl and just find the max_ind.
                // if(c==0) min_ind=q.peek().getValue();
                if(c==size-1) max_ind=q.peek().getValue();
                Long i=q.peek().getValue()-min_ind;
                q.poll();
                if(ele.left!=null) q.add(new Pair(ele.left,2*i));
                if(ele.right!=null) q.add(new Pair(ele.right,2*i+1));
            }
            mx=Math.max(mx,(max_ind-min_ind)+1);
        }
        return mx.intValue();
    }
}
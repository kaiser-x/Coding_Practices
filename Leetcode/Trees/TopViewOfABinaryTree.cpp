// Top View of Binary Tree
// MediumAccuracy: 32.3%Submissions: 100k+Points: 4
// Given below is a binary tree. The task is to print the top view of binary tree. 
// Top view of a binary tree is the set of nodes visible when the tree is viewed from 
// the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.
// Example 1:
// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3
// Example 2:
// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N).
// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105

public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {   
        
        /*Remember the vertical order traversal?? the same way we will find the height diference of each
        node from center that is root, then insert only the first node that occurs in that height diference
        ,that is the first node with HD when we travel in lvlv order manner, so the idea is to use a queue
        for level order traversal, the modificaton will be we have to store the height difference too, so
        we make a pair of them, now the map will be int ,int, one for HD and other for storing the first
        node val that has that HD,so we do lvl order traversal, pop the node and its HD, then check if the HD
        is present in tha map already, if it did not, then make the key val pair ,now we check if left child
        exissts, if it does then we push the pair of node with hd-1(as we are traversing left) into queue,
        similarly check for the right and insert into queue, now after traversing completely,in map we will
        have all numbers that appear first in each height difference from left to right.So we iterate map
        push data into resultant vector and return it.*/
        if(root==nullptr) return {};
        queue<pair<int,Node*>> q;
        map<int,int> mp;
        q.push({0,root});
        while(!q.empty()){
            Node *ele=q.front().second;
            int hd=q.front().first;q.pop();
            if(mp.find(hd)==mp.end()) mp[hd]=ele->data;
            if(ele->left!=nullptr) q.push({hd-1,ele->left});
            if(ele->right!=nullptr) q.push({hd+1,ele->right});
        }
        vector<int> res;
        for(auto p:mp){
            res.push_back(p.second);
        }
        return res;
        //DFS approach will not work bc we need to have the fisrt elemnt that occurs with a HD and also
        //occurs first in lvl order, os dfs can't work as we visit complete left or tight first corresponding
        //to how you have your dfs code.
        
        //using a queue
        /*Second method is to use a dq as we need to push fron and back, then two variablee that will give
        us the current max range to the left and right, what we are doing in the first approach, at each lvl
        if the node that occured witth a certain HD occured first then it'd we included in the map then
        later on in the result array, so we maintain  left max rannge and right max range, both variable
        give us the current max to left and the right, so if we encounter a HD that is less that current
        left max range that means that node with the particular HD is occuring for the first time,so we include
        that in our dq, but where would we include it, as it is appearing on the left side, and we need
        result from left to right, so as LR is increasing to left we push the node val in the front ,
        and update the left max range,sothat it would be used in future comparisons of HD for a node,similarly
        if a node with a HD greater than Rightmax range occurrs then we add node val to the back of dq so we
        push back and update the right max range.,then if child is present then HD-1 for left and HD+1 for right
        and push the pair in queue.At last traverse dq and insert the elements in to a result vec and return*/
        deque<int> dq;
        int lr=0,rr=0;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        //as we are comparing agains root hd 0, we have to include it in dq, because we are not gonna
        //compare hd 0 in our code that 0 is the starting base to compare,we cant have <= or >= to
        //incoporate root val, bcs then our approach will fail and it'll not make any sense.
        // dq.push_back(root->data);
        while(!q.empty()){
            Node *ele=q.front().second;
            int hd=q.front().first;q.pop();
            if(hd<lr){
                dq.push_front(ele->data);
                lr=hd;
            }else if(hd>rr){
                dq.push_back(ele->data);
                rr=hd;
            }
            if(ele->left!=nullptr) q.push({hd-1,ele->left});
            if(ele->right!=nullptr) q.push({hd+1,ele->right});
        }
        vector<int> res;
        for(auto p:dq){
            res.push_back(p);
        }
        return res;
        
    }
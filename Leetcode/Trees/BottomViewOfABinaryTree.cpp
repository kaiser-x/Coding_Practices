// Bottom View of Binary Tree
// Medium
// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look 
// at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal 
// distance from root, then print the later one in level traversal. 
// For example, in the below diagram, 3 and 4 are both the bottommost 
// nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree the output should be 5 10 4 14 25.
// Example 1:
// Input:
//        1
//      /   \
//     3     2
// Output: 3 1 2
// Explanation:
// First case represents a tree with 3 nodes
// and 2 edges where root is 1, left child of
// 1 is 3 and right child of 1 is 2.
// Thus nodes of the binary tree will be
// printed as such 3 1 2.
// Example 2:
// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 40 20 60 30

public:
  /*The same idea as the top view, but insetead of adding the first element that has a particular HD in lvl
  order manner, we here are inserting the last node with a HD on lvl order manner,so we remove that condition
  we check if the HD is already present in the map or not, we here just add the hd with root val in map.*/
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        if(root==nullptr) return {};
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            Node* ele=q.front().second;
            int hd=q.front().first; q.pop();
            mp[hd]=ele->data;
            if(ele->left!=nullptr) q.push({hd-1,ele->left});
            if(ele->right!=nullptr) q.push({hd+1,ele->right});
        }
        vector<int> res;
        for(auto p:mp) res.push_back(p.second);
        return res;
    }
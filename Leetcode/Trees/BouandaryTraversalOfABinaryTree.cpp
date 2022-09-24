// Boundary Traversal of binary tree
// Medium
// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the 
// following order: 
// Left boundary nodes: defined as the path from the root to the left-most node ie- 
// the leaf node you could reach when you always travel preferring the left subtree over 
// the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right 
// boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. 
// The right-most node is the leaf node you could reach when you always travel preferring 
// the right subtree over the left subtree. Exclude the root from this as it was already 
// included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is 
// the left or right boundary. 
// Example 1:
// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3
// Example 2:
// Input:
//             1
//            /
//           2
//         /  \
//        4    9
//      /  \    \
//     6    5    3
//              /  \
//             7     8

// Output: 1 2 4 6 5 7 8

public:
/*So we need to traverse the boundary anti clock wise, so left bottom then right,so we iterate just like that
,we traverse the left side then insert the node's val in the result array, now till when should we traverse the
left side, untill the very last left node that is not a leaf node,so when we get to the leaf node we just 
simply return, then we do an inoder traversal and insert all the leaf node, inoder traversal will give us
leaf nodes fron left to right that's why, now for right side, we do the same as left instead of compulsary
putting left side node and taking right when left is not ther, we here do compulsary right and if only if
left is not present we will take the left child,now same as before if we hit a leaf node we return, but as
the right side is needed from bottom to top, we can stor the contets in a temp array, and while inserting
it into result array we can just insert it by traversing temp in rrevers order. Now as the roof is not
a left side not a right side, but it can be leaf npde when number of nodes is 1, so we insert the root
in result array, then call the lefside function for root->left, similarly root->right for rightside funtion
,but if the root is leaf node then the leaf node will take care of that funtion,so before inserting the root
into the result array we just need to check whether its not a leaf node right, bc if it was a leaf nodde then
it can taken care by the leafnode funtion.*/
    // void leftSide(Node* root,vector<int> &res){
    //     if(root==nullptr) return;
    //     if(root->left==nullptr&&root->right==nullptr) return;
    //     res.push_back(root->data);
    //     if(root->left!=nullptr) leftSide(root->left,res);
    //     else leftSide(root->right,res);
    // }
    void leafSide(Node *root,vector<int> &res){
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr) res.push_back(root->data);
        leafSide(root->left,res);
        leafSide(root->right,res);
    }
/*Now the above approach is current only, but it can be done iteratively too, as we are just going left left or
right right and only going to the other child when left right is not present in its respective funtions.
so we can sstart from the left  and rightchild of root (if exists),and pass them to respective left and right
side funtions, and run the while loop,so to exist the loop there are 2 ways, either we can run the loop till
there are nodes, adn at each iteraation if the current node is not null then we add them to result arrray or
temp array respectively, or we can break out of the loop once we hit a leaf node(just like in dfs), then
similary to dfs we need to go left if theres one and only go right if left is not present, this approach
makes sure that we traverse only the extream left side of the tree, and similar for the right side*/
     void leftSide(Node* root,vector<int> &res){
        Node* curr=root;
        while(curr!=nullptr){
            //if the node is not leaf node insert it into the result
            if(curr->left!=nullptr||curr->right!=nullptr)  res.push_back(curr->data);;
            if(curr->left!=nullptr) curr=curr->left;
            else curr=curr->right;
        }
    }
    // void rightSide(Node* root,vector<int> &temp){
    //     if(root==nullptr) return;
    //     if(root->left==nullptr&&root->right==nullptr) return;
    //     temp.push_back(root->data);
    //     if(root->right!=nullptr) rightSide(root->right,temp);
    //     else rightSide(root->left,temp);
    // }
    void rightSide(Node* root,vector<int> &temp){
        Node* curr=root;
        while(curr!=nullptr){
            //not leaf node add it to the temp array.
            if(curr->left!=nullptr||curr->right!=nullptr) temp.push_back(curr->data);
            if(curr->right!=nullptr) curr=curr->right;
            else curr=curr->left;
        }
    }
    vector <int> boundary(Node *root)
    
    {
        vector<int> res;
        if(root==nullptr) return res;
         if(root->left!=nullptr||root->right!=nullptr) res.push_back(root->data);
        leftSide(root->left,res);
        leafSide(root,res);
        vector<int> temp;
        rightSide(root->right,temp);
        for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
        return res;
        
    }
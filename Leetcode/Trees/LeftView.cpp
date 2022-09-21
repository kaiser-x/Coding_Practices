// Left View of Binary Tree
// Easy
// Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes 
// visible when tree is visited from Left side. The task is to complete the function 
// leftView(), which accepts root of the tree as argument.
// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Example 1:
// Input:
//    1
//  /  \
// 3    2
// Output: 1 3
// Example 2:
// Input:
// Output: 10 20 40
/*so if you clearly observe the given tree then it would be clear that for left view we are printing the
first node that occurs in each lvl,so we keep a set that will let us know whether the lvl has already
been considereed for output, i,e di we take the first node of this lvl in our iutput or not, so we have
a set for that, then we have the output array, then we make a dfs call and at each call we check if the
current lvl is alrady present in th set , if it doesn't then we add that node to result array, then add
the lvl to the set, hen we make left dfs ,as we need the first node from left side and then if left
not present then we need to check for right, but we dont need those left not present check and all, bcs
the set lvl check will take care of it.*/
void dfs(Node *root,int lvl,vector<int> &res,unordered_set<int> &st){
    if(root==nullptr) return;
    if(st.find(lvl)==st.end()){
        res.push_back(root->data);
        st.insert(lvl);
    }
    dfs(root->left,lvl+1,res,st);
    dfs(root->right,lvl+1,res,st);
}
/*Now the above approach is okay, but we are using a set so it hash a size of number of lvls, and theres
a way to reducce this, we need to take the first node in each lvl, we try to take the first node by making
dfs left call first and then right,so getting first left is sorted by havinf left dfs first and then right 
dfs, but what about the check whether the node that is occuring is first in that lvl,so we can make use
of the size of the output array, as we insert the first node in each lvl, so if we add a node then the size
of the output array will also increase right? we can use that and check if the curent lvl is equal to
the array size, if it is then we add it, for eg if lvl 2 and array size 2, then we add that node with
lvl 2 ,then array size become 3,now if any othe node with lvl 2 comes it will not be inserted.*/
void dfs1(Node *root,int lvl,vector<int> &res){
    if(root==nullptr) return;
    if(lvl==res.size()) res.push_back(root->data);
    dfs1(root->left,lvl+1,res);
    dfs1(root->right,lvl+1,res);
}
vector<int> leftView(Node *root)
{
   if(root==nullptr) return {};
   vector<int> res;
   unordered_set<int> st;
//   dfs(root,0,res,st);
    dfs1(root,0,res);
   return res;
}
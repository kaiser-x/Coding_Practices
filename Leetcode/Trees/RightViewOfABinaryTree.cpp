// Right View of Binary Tree
// Easy
// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of 
// nodes visible when tree is viewed from right side.
// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8
// Example 1:
// Input:
//        1
//     /    \
//    3      2
// Output: 1 2
public:
    /*Same as left view but instead of first going left we will first go right so that we get the first node
    from the right side.*/
    void dfs(Node *root,int lvl,vector<int> &res,unordered_set<int> &st){
        if(root==nullptr) return ;
        if(st.find(lvl)==st.end()){
            res.push_back(root->data);
            st.insert(lvl);
        }
        dfs(root->right,lvl+1,res,st);
        dfs(root->left,lvl+1,res,st);
    }
    void dfs1(Node *root,int lvl,vector<int> &res){
        if(root==nullptr) return ;
        if(lvl==res.size()) res.push_back(root->data);
        dfs1(root->right,lvl+1,res);
        dfs1(root->left,lvl+1,res);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> res;
       if(root==nullptr) return res;
       unordered_set<int> st;
    //   dfs(root,0,res,st);
        dfs1(root,0,res);
       return res;
    }
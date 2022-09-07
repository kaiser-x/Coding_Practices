// 606. Construct String from Binary Tree
// Easy
// Given the root of a binary tree, construct a string consisting of parenthesis and integers
// from a binary tree with the preorder traversal way, and return it.
// Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship 
// between the string and the original binary tree.
// Example 1:
// Input: root = [1,2,3,4]
// Output: "1(2(4))(3)"
// Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
// Example 2:
// Input: root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we cannot omit the first 
// parenthesis pair to break the one-to-one mapping relationship between the input and the 
// output.
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -1000 <= Node.val <= 1000

//cpp
class Solution {
public:
    /*DFS- The approach is to check if both the child of a node exists or not ,if it does then we append opening bracket (, then 
    append the child's value then make a dfs caall to that child, the append the clossing bracket ) when the call is completed,but
    there's a catch for the left child,explained below.*/
    void dfs(TreeNode* root,string &res){
        //We need to include brackets for left child if theres a left child or even when theres no left child
        //but there exists a right child
        if(root->right!=NULL||root->left!=NULL) { 
            res+='(';
            //we could have reached this if on two choices , if left child is there then string would be
            //(left child value), but if we reached this if bcs there's a right child then string would be
            //(),so we need to check if the left is null before assigning value and before making the dfs
            //call to it's left.
            if(root->left!=NULL) res+=to_string(root->left->val);
            if(root->left!=NULL) dfs(root->left,res);
            res+=')';
        }
        //if there are right child then include those brackets.
        if(root->right!=NULL){
            res+='(';
            //here we dont need to check if child is null bcs we reached this if only bcs the right child 
            //exists.
            res+=to_string(root->right->val);
            dfs(root->right,res);
             res+=')';
        }
       
    }
    string dfsR(TreeNode* root){
        //here if we hit a null node we return empty string bc null is not considered in answer
        // except the left null when theres a right child
        //which is gonna be handeled by code itsel
        if(root==nullptr) return "";
        string s="";
        s+=to_string(root->val);
        if(root->left!=nullptr) s+="("+ dfsR(root->left) + ")";
        else if(root->right!=nullptr) s+="()";
        if(root->right!=nullptr) s+="(" + dfsR(root->right) + ")";
        return s;
    }
    string tree2str(TreeNode* root) {
        //As the first root number does not have any brackets we initalise the string with root value.
        //And we dont check for null condition here bcs in constraints it is given that the number of node
        //lowest value is 1.
        // string res=to_string(root->val);
        // dfs(root,res);
        // return res;
        //the above dfs method is my intuition method , the common dfs method used is to calculate 
        // the string for the current node unlike mine
        //where I already declared string with root val, then calculate the string for the 
        // child node from the parent perspective.
        return dfsR(root);
        
    }
};

//java
class Solution {
    static void dfs(TreeNode root,StringBuilder res){
        if(root.right!=null||root.left!=null){
            res.append('(');
            if(root.left!=null) res.append(String.valueOf(root.left.val));
            if(root.left!=null) dfs(root.left,res);
            res.append(')');
        }
        if(root.right!=null){
            res.append('(');
            res.append(String.valueOf(root.right.val));
            dfs(root.right,res);
            res.append(')');
        }
    }
    public String tree2str(TreeNode root) {
        StringBuilder res=new StringBuilder(String.valueOf(root.val));
        dfs(root,res);
        return res.toString();
    }
}
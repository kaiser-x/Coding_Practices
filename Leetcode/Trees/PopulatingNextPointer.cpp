// 116. Populating Next Right Pointers in Each Node
// Medium
// You are given a perfect binary tree where all leaves are on the same level, and every 
// parent has two children. The binary tree has the following definition:
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node,
// the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// Example 1:
// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate
// each next pointer to point to its next right node, just like in Figure B. The serialized 
// output is in level order as connected by the next pointers, with '#' signifying the end 
// of each level.

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        //This is my naive bruteforce approach, we traverse level wise then make next point
        //using bfs method of queue.
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node* prev=NULL,*ele;
            for(int i=0;i<size;i++){
                ele=q.front();
                q.pop();
                if(prev!=NULL) prev->next=ele;
                prev=ele;
                if(ele->left!=NULL) q.push(ele->left);
                if(ele->right!=NULL) q.push(ele->right);
            }
            ele->next=NULL;
        }   
        return root;
        //we can use dfs too, but whata we are gonna do is we gonna make use oof the next pointer
        //given is a perfect binary tree, that means it'll have 2 child for a node or no child.
        //now to check for end check if the current node has left child or not, if it doesn't we
        //can return, else we can assign the current nodes left child's next to current node right child
        //now to make use of the next pointer, we can check if the current node has next value, if it does
        //then we can point the current nodes right child's next to current nodes next's left child, now
        // the next will definitly have leftchild because this is a perfect binary tree;.
        if(root->left!=NULL){
            root->left->next=root->right;
            if(root->next!=NULL) root->right->next=root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
        //Now we got the understanding of how we can use next pointer, now use the same technique we
        //are gonna traverse level wise without using queue, in place alfo, for that what we need to
        //do is traverse every left, then use the next pointer to traverse evel wise
        //NOTE this wil only work for perfect tree and with next pointer.
        Node* res=root;
        while(root->left!=NULL){
            Node* cur=root;
            while(cur!=NULL){
                if(cur->left!=NULL){
                    cur->left->next=cur->right;
                    if(cur->next!=NULL) cur->right->next=cur->next->left;
                }
                cur=cur->next;
            }
            root=root->left;
        }
        return res;
    }
};
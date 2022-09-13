// Flattening a Linked List
// Medium
// Given a Linked List of size N, where every node represents a sub-linked-list and contains 
// two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead 
// of next pointer. For more clearity have a look at the printList() function in the driver 
// code.
// Example 1:

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation:
// The resultant linked lists has every 
// node in a single level.
// (Note: | represents the bottom pointer.)

 Node* merge2Lists(Node *h1,Node* h2){
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        Node* dummy=new Node(-1);
        Node* ptr=dummy;
        while(h1!=NULL&&h2!=NULL){
            if(h1->data<h2->data){
                ptr->bottom=h1;
                h1=h1->bottom;
            }else {
                ptr->bottom=h2;
                h2=h2->bottom;
            }
            ptr=ptr->bottom;
        }
        if(h1!=NULL) ptr->bottom=h1;
        if(h2!=NULL) ptr->bottom=h2;
        return dummy->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
   //We will use the merge2lists method.
   if(root==NULL||root->next==NULL) return root;
   //SO we have two or more lists now,so we take the first list then call merge2lisst on the root and root->next
   //the returned pointer will be assigned to root again, before calling the merge we can store the third list's
   //head or null if the third list doesnt exist and second list points to null,then after merge we can assign
   //the root next as that temp node.at last return root as itll have pointer of result list and its next will
   //be pointed to null
    //as we are calling merge for root and root next,we need to check if root next exists or not.
    while(root!=NULL&&root->next!=NULL){
        Node* temp=root->next->next;
        root=merge2Lists(root,root->next);
        root->next=temp;
    }
    return root;
}
// 21. Merge Two Sorted Lists
// Easy
// You are given the heads of two sorted 
// linked lists list1 and list2.
// Merge the two lists in a one sorted list. 
// The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
//Cpp

class Solution {
public:
    //2 ways to merge recursive and iterative.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Recursive
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<list2->val){
            //is this node is smallest then,we knw this is our answer,so we select this node and for its next node we don't know so we call the merge function recursively,then when we reach bak the current call, we have to return the list1 so that it can be assigned as the next for the node from where the current call was made.
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }else {
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        //Iterative
/*First to use a dummy pointer then a ptr traversing pointer, and as we traverse assign the smallest node to ptr next then move ptr, at end if any of the two ll will be not null, that is not traversed completely assign its pointer to ptr next and return dummy next. we use dummy when we are unsure of which noe will become our answer head.*/
        ListNode* dummy=new ListNode(-1);
        ListNode *ptr=dummy;
        //We are assiging th eptr next untill either of the two lists is completely traversed
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<list2->val){
                //if the current smallest node is h1 then assign tha tnode to ptr next and move the h1 to its next.
                ptr->next=list1;
                list1=list1->next;
            }else{
                ptr->next=list2;
                list2=list2->next;
            }
            
            //now move ptr to its next
            ptr=ptr->next;
        }
        //now one of the list is not traversed completely and as it is in sorted ordered we can 
        // just assign it to ptr next
        if(list1!=NULL) ptr->next=list1;
        else ptr->next=list2;
        //now our result head will be present at dummy next;
        return dummy->next;
        
        //2nd approach without using dummy;
        //here we are sure that h1 will be our smallest head always if not, then we make it 
        // smalles by swaping.
        if(list2->val<list1->val){
            //if h2 is smaller than h1 then swap them
            swap(list1,list2);
            //Or
            /*ListNode *temp=list1;
            list1=list2;
            list2=temp;*/
        }
        /*the Idea is simple, we traverse h1 whilist storing our previous h1 in prev, untill we encounter a node 
        where the h2 is smaller than h1, then we map the previous h1,which was smaller than h2,
        how do we map, take prev->next=h2,now, we need to move to smaller node value, so we 
        swap h1 and h2,the whole resultant list is being mapped by h1 and prev.*/
        //To return resultant head;
        ListNode *head=list1,*prev=NULL;
        while(list1!=NULL&&list2!=NULL){
            while(list1!=NULL&&list1->val<=list2->val){
                prev=list1;
                list1=list1->next;
            }
            prev->next=list2;
            swap(list1,list2);
        }
        return head;
    }
};

//java

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null) return l2;
        if(l2==null) return l1;
        //Recursive
        if(l1.val<l2.val){
            l1.next=mergeTwoLists(l1.next,l2);
            return l1;
        }else {
            l2.next=mergeTwoLists(l1,l2.next);
            return l2;
        }
        //Iterative
        if(l1.val>l2.val){
            ListNode t=l1;
            l1=l2;
            l2=t;
        }
        ListNode res=l1;
        ListNode prev=null;
        while(l1!=null&&l2!=null){
            while(l1!=null&&l1.val<=l2.val) {
                prev=l1;
                l1=l1.next;
            }
            prev.next=l2;
            ListNode t=l1;
            l1=l2;
            l2=t;
            
        }
        return res;
    }
}
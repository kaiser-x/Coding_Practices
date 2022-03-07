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

class Solution {
public:
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(list1==NULL) return list2;
    //     if(list2==NULL) return list1;
    //     ListNode* dummy=new ListNode(-1);
    //     ListNode *l1=list1,*l2=list2,*ptr=dummy;
    //     while(l1!=NULL&&l2!=NULL){
    //         if(l1->val<l2->val){
    //             ptr->next=l1;
    //             l1=l1->next;
    //         }else {
    //             ptr->next=l2;
    //             l2=l2->next;
    //         }
    //         ptr=ptr->next;
    //     }
    //     while(l1!=NULL){
    //         ptr->next=l1;
    //         l1=l1->next;
    //         ptr=ptr->next;
    //     }
    //     while(l2!=NULL){
    //         ptr->next=l2;
    //         l2=l2->next;
    //         ptr=ptr->next;
    //     }
    //     return dummy->next;
    // }
    
    //without extra dummy node
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
       //assigning the smallest as l1 and other as l2
        ListNode *l1=list1,*l2=list2;
        if(l1->val>l2->val) {swap(l1,l2);}
        ListNode* res=l1;
        while(l1!=NULL&&l2!=NULL){
            ListNode* ptr=NULL;
            while(l1!=NULL&&l1->val<=l2->val){
                ptr=l1;
                l1=l1->next;
            }
            ptr->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};
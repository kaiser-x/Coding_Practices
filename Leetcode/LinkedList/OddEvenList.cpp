// 328. Odd Even Linked List
// Medium
// Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it 
// was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
// Constraints:
// The number of nodes in the linked list is in the range [0, 104].
// -106 <= Node.val <= 106
// cpp code:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return head;
        ListNode* odd=head, *even=head->next,*evenhead=even;
        //since we are assigning the next elements ,we iterate till there are next element, odd's next will
        //be for even, and even next will be for odd.
        /*What we need to do understand is, as said before we are assigning the next node to odd or even group,so we
        need to check if the next is present or not.But onother hand, if you check correctly you will not that
        if the number of node is  odd then the ven pointer wil point to null, as the last node will be odd and
        we will make even->next as odd->next and move even=even->next , that is null, and when number of nodes
        is even then the even pointer will be at the last node, does that mean now odd will move to even next that
        is null?? no bcs we have condtion in while ,so that if even->next==null then we break,so in other words
        we runn while lopp until even is not null and even->next is not null*/
        //odd->next!=NULL&&even->next!=NULL, even!=NULL&&even->next!=NULL, bot will work, and now you know why.
        while(even!=NULL&&even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        // if(even==NULL) cout<<"yeseve ";
        // if(odd=NULL) cout<<"yesodd ";
        //we dont need to explicitly set the even next to null, as even will point to last node which already has
        //its next pointed to null, or it will point to null so it doesnt have any next.
        // even->next=NULL;
        return head;
    }
};

java code:

class Solution {
    public ListNode oddEvenList(ListNode head) {
        //if not node, if only one node, or if only two nodes, then return head.
        if(head==null|| head.next==null||head.next==null) return head;
        ListNode odd=head,even=head.next,evenHead=even;
        while(even!=null&&even.next!=null){
            odd.next=even.next;
            odd=odd.next;
            even.next=odd.next;
            even=even.next;
        }
        odd.next=evenHead;
        return head;
    }
}
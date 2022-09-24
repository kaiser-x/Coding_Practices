// 148. Sort List
// Medium
// Given the head of a linked list, return the list after sorting it in ascending order.
// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:
// Input: head = [-1,5,3,4,0]

//cpp

class Solution {
public:
    /*So this is similar to merge sort, it is merge sort on Linked List, so same as merge sort, we have to find the
    middle then partition the LL into subb parts then sort them them and combine those sorted part again into a
    singuar LL, SO the first part Subdividing the LL in half, we will keep on doing this recursively untill we 
    encounter either null or single node , at that base case we will return the head, now the second part is how we
    are gonna divide in half, so the process is to find the middle element, now to find middle and first one is
    to find the middle node then we can make the next of this node as the starting node for the other half, and
    the middle node as the last node for the first half, next approach is to take the middle, and we make this middle
    node as the starting node for thesecond half and the previous node to the middle node as the lasst node for first
    half, now let me explaiang the first approach, we typically start slow and fast from head but here we will
    start fast from head->next what difference will it make, well if the length is odd lets say 5 then slow will
    like usual point to 3,but if length is even  like 4 then the slow will point to 2, but if we have fast=head then
    slow will point to 3,so what does this have to do with our solution well, we are taking mid, them taking the
    middile->next as our right and the head as our left which is used to call merge funtion, and we make the next of
    middle node as node so that we can split the LL into two halfs, so we will basically get TLE if we have fast
    =head while finding middle node, bcs imagine we have 2 nodes, now if we have fast=head, then as we iterate
    fast will point to null, and slow will point to 2,now we return slow as mid, so we make mid->next as right and 
    current head as left,then we make mid->next as null, which is already null,so once again when we make recursive
    call for left, it is again pointing to the same node with 2 nodes 1 and 2 where the next of 1 is not made null,so
    for our solution to work when there are two node 1 and 2 we need to return mid as 1 so that we can make its next
    as null make recursive call hit the base case and return and call merge with left and right,and to get mid liek
    that we need to start from f=head->next, bcs if we did that the fast will point at 2 and as fast is pointing
    at last node the control will not even go into the while loop and 1 will be return as mid as slow will point to 
    node 1,now to discuss the second approach,we keep a prev node that keeps track of the previous slow,as we take
    the slow as mid,and that mid as our right,to break the LL into two halves we store previous slow, and make
    its' next prev->next as null,so in both approach if you look closely we are only changing the mid when legnth is
    even, but the right is always same in both approac, lenght 4, first approach mid will be 2, then 2->next 3 would
    be right, now in second approaach 3 will be mid which will be our right, okay, then now third part is making 
    recursive call to left LL and right LL halves, adn when they comeback we merge both of the LL halve and return
    the head of the merged List.*/
    ListNode* mid1(ListNode *h){
        ListNode *slow=h,*fast=h->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mid2(ListNode* h){
        ListNode *slow=h,*fast=h,*prev=slow;
        while(fast!=nullptr&&fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }
    ListNode* merge2Lists(ListNode *h1,ListNode *h2){
        if(h1==nullptr) return h2;
        if(h2==nullptr) return h1;
        ListNode *dummy=new ListNode(-1);
        ListNode *ptr=dummy;
        while(h1!=nullptr&&h2!=nullptr){
            if(h1->val<=h2->val){
                ptr->next=h1;
                h1=h1->next;
            }else{
                ptr->next=h2;
                h2=h2->next;
            }
            ptr=ptr->next;
        }
        if(h1!=nullptr) ptr->next=h1;
        else ptr->next=h2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        //First mid approach
        // ListNode *middle=mid1(head);
        // ListNode *left=head,*right=middle->next
        // middle->next=nullptr;
        //Second mid approach
        ListNode *middle=mid2(head);
        ListNode *left=head,*right=middle;
        // ListNode *lh=sortList(left);
        // ListNode *rh=sortList(right);
        //It can be left and right to, we can overwrite them as we dont need their prev values.
        left=sortList(left);
        right=sortList(right);
        return merge2Lists(left,right);
        
    }
};

//java

class Solution {
    ListNode mid1(ListNode h){
        ListNode slow=h,fast=h.next;
        while(fast!=null&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    ListNode mid2(ListNode h){
        ListNode slow=h,fast=h,prev=slow;
        while(fast!=null&&fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        prev.next=null;
        return slow;
    }
    ListNode merge2Lists(ListNode h1,ListNode h2){
        if(h1==null) return h2;
        if(h2==null) return h1;
        ListNode dummy=new ListNode(-1);
        ListNode ptr=dummy;
        while(h1!=null&&h2!=null){
            if(h1.val<=h2.val){
                ptr.next=h1;
                h1=h1.next;
            }else{
                ptr.next=h2;
                h2=h2.next;
            }
            ptr=ptr.next;
        }
        if(h1!=null) ptr.next=h1;
        else ptr.next=h2;
        return dummy.next;
    }
    ListNode sortList(ListNode head) {
        if(head==null||head.next==null) return head;
        //First mid approach
        // ListNode middle=mid1(head);
        // ListNode left=head,right=middle.next
        // middle.next=null;
        //Second mid approach
        ListNode middle=mid2(head);
        ListNode left=head,right=middle;
        // ListNode lh=sortList(left);
        // ListNode rh=sortList(right);
        //It can be left and right to, we can overwrite them as we dont need their prev values.
        left=sortList(left);
        right=sortList(right);
        return merge2Lists(left,right);
        
    }
}
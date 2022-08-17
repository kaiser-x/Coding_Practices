```
CPP Code:

class Solution {
public:
    /* So list length to be len, and we have slow and fast pointing to head,we have to delete
    the nth element from last,so total is len, last sub part is n then another sub part is 
    len-n, now if we we traverse n times from start using fast, then other part is len-n size,
    then we have slow move and fast also move, when fast reaches end that means fast has
    traveled len-1 there for the other part that is traveld by slow also travel len-n times
    this way we did not find length aand then traverse till len-n and deleted that node,
    instead we use the fore mentioned method. The edge case is when n equal lenght, the we
    return next element of head*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head==NULL) return NULL;
        ListNode *ptr=head,*slow=head,*fast=head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        //if n is equal to length of the list that mean we have to delete the head
        if(fast==NULL) return head->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return ptr;
    }
};

Java Code:

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return null;
        ListNode ptr=head,slow=head,fast=head;
        while(n>0){
            fast=fast.next;
            n--;
        }
        if(fast==null) return head.next;
        while(fast!=null&&fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
        slow.next=slow.next.next;
        return ptr;
    }
}
```
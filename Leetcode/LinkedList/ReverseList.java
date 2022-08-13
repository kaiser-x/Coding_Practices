/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        //recursively
        // ListNode* helper(ListNode* curr,ListNode* prev){
        //     if(curr==NULL) return prev;
        //     ListNode* next=curr->next;
        //     curr->next=prev;
        //     return helper(next,curr);
        // }
        ListNode* reverseList(ListNode* head) {
            //recursively
            // return helper(head,NULL);
            
            //iteratively
            
            ListNode* curr=head,*next=NULL,*prev=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    };
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode temp=null;
        ListNode next=null;
        while(head!=null){
            next=head.next;
            head.next=temp;
            temp=head;
            head=next;
        }
        return temp;
    }
}
// 61. Rotate List
// Medium
// Given the head of a linked list, rotate the list to the right by k places.
// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
// Constraints:
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        //brute
        // //if no list element
        // if(head==NULL) return head;
        // ListNode* temp=head;
        // int n=0;
        // while(temp!=NULL) {
        //     n++;
        //     temp=temp->next;
        // }
        // k=k%n;
        // //if only one element or no rotation k=0
        // if(n==1||k==0) return head;
        // int count=0;
        // //traverse it node before n-kth node
        // temp=head;
        // while(count<n-k-1){
        //     temp=temp->next;
        //     count++;
        // }
        // //store n-kth node
        // ListNode* temp2=temp->next;
        // ListNode* t=temp2;
        // //make the node before n-kth node's next as null;
        // temp->next=NULL;
        // //now traverse till end and change its next to head
        // while(temp2->next!=NULL) temp2=temp2->next;
        // temp2->next=head;
        // //return the n-kth node;
        // return t;
        
        //now there's a more optimized way,i mean same o(n) but somehwat bettter than
        //complete bruteforce, when we find n value then we are at the end node ,so instead of 
        //traversing from n-kth node to last node and then assigning next as head(As
        // we did earliear) we can just put next as head in here,then traverse to node
        //before n-kth node ,store the next node ,now assign next of the node before
        //n-kth node as null,now return the stored node i.e n-kth node
        
        //to check if no node,only one node and k=0 ,we can do all that in single line;
        if(head==NULL||head->next==NULL||k==0) return head;
        int n=0;
        ListNode* temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
            n++;
        }
        //now as we are just traveling till last node,the control will come out of
        //while loop and n will not be increemented for the last node ,so there are 3 wasy to
        //solve this problem ,1) keep n=1 instead of n=0 ,or 2) increement n by 1 after the
        //while loop,or 3) use a do while loop,I am going to 2 way and increement n by 1
        n+=1;
        k=k%n;
        //k was multiple of n and was ov=bviously greater than 0 at first
        //but k multiple means no need for rotation
        if(k==0) return head;
        //we have to set the last node's next as head 
        temp->next=head;
        //now we need to break the link between node before n-kth node and n-kth node
        //instead of having count variable and going till n-k lets change k value
        k=n-k;
        //now theres two ways ,the temp is at lastnode( or atleast was the last node) so we 
        //travel from there to +kth node or we can change temp to head and travel from
        //head to +kth -1 node,both work fine to reach the node before n-kth node,
        // i am following first method
        
        while(k--){
            temp=temp->next;
        }
        //now here;s two ways to ,we can store the n-kth node in other ListNode* pointer
        //or just replace head with it,I am following 1st one
        head=temp->next;
        //now break link between node before n-kth node and n-kth node
        temp->next=NULL;
        //return the n-kth node
        return head;
        
        
    }
};
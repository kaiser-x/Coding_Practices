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
    private: ListNode* reverse(ListNode* node,int l,int r){
        if(node==NULL) return NULL;
        int i=l;
        ListNode* prev=NULL;
        ListNode* current=node;
        ListNode* next;
        ListNode* ptr;
        while(current!=NULL){
            
            next=current->next;
            
            current->next=prev;
            prev=current;
            current=next;
            i++;
            if(i==r+1){
                ptr=current;
                break;
            }
        }
        node->next=ptr;
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return NULL;
        int i=1;
        ListNode* ptr=head;
        if(left==1) head=reverse(ptr,left,right);
           else{ while(++i<=left-1) ptr=ptr->next;
            ptr->next=reverse(ptr->next,left,right);
           }
        return head;
        
    }
};


//easy one using vector
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || !head || !head->next)return head;
             
        ListNode* temp = head;
        vector<int> order;
        
        while(temp != NULL)
        {
            order.push_back(temp->val);
            temp=temp->next;
        }
        
        reverse(order.begin() + left - 1 , order.begin() + right);
        int index = 0;
        temp = head;
        
        while(temp != NULL)
        {
            temp->val = order[index++];
            temp = temp->next;
        }
        
        return head;
        
    }
};
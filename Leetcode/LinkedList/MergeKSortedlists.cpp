// 23. Merge k Sorted Lists
// Hard
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending 
// order.
// Merge all the linked-lists into one sorted linked-list and return it.
// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:
// Input: lists = []
// Output: []
// Example 3:
// Input: lists = [[]]
// Output: []
// Constraints:
// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

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
//CPP 

class compare{
    public:
  bool operator()(ListNode *a,ListNode *b)  {
      //as pq fills bottom to top, we need the smallest elment at top,so we insert the greater elemnt first so tha
      //it can fill from bottom to top, in this manner the top element will be minimum element.
      if(a->val>b->val) return true;
      return false;
  }
};
class Solution {
public:
    /*So the first approach is we will use the merge 2 sorted list , we take any two list from the k sorted lists,
    merge them then return the merged list, the call the merge2lists with the current merged list with the next 
    list from the k sorted list, So we are reducing lists k-1, so we have to call the merge2list funtion k-1 times*/
    ListNode* merge2Lists(ListNode* h1,ListNode* h2){
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        if(h2->val<h1->val){
            ListNode* temp=h1;
            h1=h2;
            h2=temp;
        }
        ListNode* head=h1;
        ListNode* prev=NULL;
        while(h1!=NULL&&h2!=NULL){
            /*Intreseting thing tI found that, the condition h1->val<=h2->val,  if by mistake we write it as 
            h1->val<h2->val, it will give tle, bc imagine if the h1 and h2 val are same, then what are we doing
            we are making prev to point to h2 then swaping h2 with h1, but now again h1 and h2 val are same
            so we have to make sure it is <= */
            while(h1!=NULL&&h1->val<=h2->val){
                prev=h1;
                h1=h1->next;
            }
            prev->next=h2;
            ListNode* temp=h1;
            h1=h2;
            h2=temp;
            
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        if(n==0) return NULL;
        //first method using merge 2 sorted list condition.
        /*Assume n is the longest length of a list from the k lists, and then n*k would be assume the total number of
        nodes, if we merge two list of size n,at worst the number of comparisons will be n+n that is 2n, then for
        second will 2n+n=3n, 2n+3n+4n+5n...kn, just like 1+2+3..+n=n(n+1)/2, here n is common k is changing
        therefore it would be n*((k(k+1)/2)-1),-1 bcs there is no 1n,so we subtract 1, therefor the TC would be
        O(nk^2) and SC= O(1)*/
        ListNode* k=lists[0];
        for(int i=1;i<n;i++){
            k=merge2Lists(k,lists[i]);
        }
        return k;
        
        /*second method is to use the priotity queue. that is min heap
        There are n*k node, andfor each we are having insert and delete operations done and each
        operations is logk (k number of lists,as we are inserting at max k pointers)
        TC:O(nk*logk), SC:O(logk)*/
        
        /* How does this work we take the head of all the k lists, then we take the minimum of them in our answers,
        then pop that node from queue, then insert the next node of that node ,in this manner we keeping pickong the
        minimum and moving then inserting the next node of the corresponding node that was poped.
        We need to have a dummy node bcs we dont know which pointer will become the head,so we have a dummy node
        and a traversing pointer ptr pointing to dummy, now the head of the result list would be the next of
        dummy node,and as we need to assign the next of each node we have ptr as traversing pointer.*/
        ListNode *dummy=new ListNode(-1);
        ListNode * ptr=dummy;
        
        /*Since we are sorting by value and we need the node adrees, we create a pair of int for val and ListNode*
        for address, and then populate the pq with the head pf all k listis that are not null*/
        
        //Min heap
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>> pq;
        
        //We need to avoid the empty lists so we check for the null list and insert only no null heads
        for(int i=0;i<n;i++) if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        
        /*Now we know the pair at top will have smallest val and its address,we get the address, that is we get the
        node at that adrees, and pop it from queue, now we assign the traversing pointer ptr's next as the current
        poped node, then move the pointer to it's next, now if and only if the next of the popped node is not null
        we insert the pair of next node's val and it's address*/
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            ptr->next=node;
            ptr=ptr->next;
            if(node->next!=NULL) pq.push({node->next->val,node->next});
        }
        return dummy->next;
            /*We can just pass ListNode* into pq instead of pair, by using a comparator,rest will be the same */
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<n;i++) if(lists[i]!=NULL) pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            ptr->next=node;
            ptr=ptr->next;
            if(node->next!=NULL) pq.push(node->next);
        }
        return dummy->next;
        /*3rd approach, we are gonna reduce the space complexity to O(1), we are gonna travers and merge two list
        like in checking if string is palindrome or not we are gonna merge i and n-i-1,then we keep on doing that 
        untill there exists only single list then we return that list, so at each iteration the size of the list
        is reduced by half, k->k/2->k/4...2->1, similarly size of the resultant is increase by n,n->2n->4n...
        2^logk->1, log k bcs atmax the lists can be subdivided logk times, then TC would be k.n+k/2.2n+k/4.4n...
        2^logk.n.1, => nk+nk+nk => nklogk, TC:O(nklogk), SC:O(1)*/
        int k=n;
            while(k>1){
                for(int i=0;i<k/2;i++){
                    lists[i]=merge2Lists(lists[i],lists[k-i-1]); 
                }
        // as we traversing index before (k/2)-1, we need to increase current k+1, then divide it by 2
                k=(k+1)/2;
            }
            return lists[0];
        //the above loop is kinda confusing as we have to do k+1/2
        int end=n-1;
        while(end>0){
            int begin=0;
            while(begin<end){
                lists[begin]=merge2Lists(lists[begin],lists[end]);    
                begin++;
                end--;
            }
        }
        return lists[0];
    }
};

//Java

class Solution {
    private static final Comparator<ListNode> compare=new Comparator<ListNode>(){
        public int compare(ListNode a,ListNode b){
            return a.val-b.val;
        }
    };
    ListNode merge2Lists(ListNode h1,ListNode h2){
        if(h1==null) return h2;
        if(h2==null) return h1;
        if(h2.val<h1.val){
            ListNode temp=h1;
            h1=h2;
            h2=temp;
        }
        ListNode head=h1,prev=null;
        while(h1!=null&&h2!=null){
            while(h1!=null&&h1.val<=h2.val){
                prev=h1;
                h1=h1.next;
            }
            prev.next=h2;
            ListNode temp=h1;
            h1=h2;
            h2=temp;
        }
        return head;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int n=lists.length;
        if(n==0) return null;
        //First approach Merging two lists then hte resultant with the next list and so on ,not so fast
        for(int i=1;i<n;i++) lists[0]=merge2Lists(lists[0],lists[i]);
        return lists[0];
        
        //second approach is to use a priority queue
        //we need to pass a comparator.
        PriorityQueue<ListNode> pq=new PriorityQueue<>(compare);
        for(int i=0;i<n;i++) if(lists[i]!=null) pq.add(lists[i]);
        ListNode dummy=new ListNode(-1);
        ListNode ptr=dummy;
        while(!pq.isEmpty()){
            ListNode node=pq.poll();
            ptr.next=node;
            ptr=ptr.next;
            if(node.next!=null) pq.offer(node.next);
        }
        return dummy.next;
        
        //3rd approach with divide and conquer method
        int end=n-1;
        while(end>0){
            int begin=0;
            while(begin<end){
                lists[begin]=merge2Lists(lists[begin],lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }
}
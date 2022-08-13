
/****************************************************************
	Following is the Linked list node structure already written:

	template <typename T>
	class LinkedListNode {
	public:
		T data;
		LinkedListNode* next;
		LinkedListNode* arbit;

		LinkedListNode(T data) {
			this->next = NULL;
			this-> arbit = NULL;
			this->data = data;
		}
	};

*****************************************************************/
#include<list>
LinkedListNode<int>* populateArbit(LinkedListNode<int>* head)
{
	// Write your code here.
    //i have followed the same steps like finding the maximum in k size window
    //here the k size is 1,so whenever we iterate an element x we have to assign
    //the maximum element y's node on the right side to the arbit pointer of
    //x, for this we maintain a list just like that question i mentioned above
    //the idea is to to insert an element i in list if it's empty and iterate,
    //then we encounter an element j which is greater than i so we pop i and
    //insert j, that is list front contains maximum element and it decrease as
    //we go to the back,so as we iterate if an element k is encountered, all the
    //element that are smaller than k on the left side and are present in the
    //list , are needed to be removed in order to maintain the list purpose, but
    //all the elements that are smaller than k on the rightside are not 
    //redundant, as they mighty become maximum for other elements after k, so 
    //they are added to the list,so the idea is,iterate ,take an element x,check 
    //if list is empty then insert it,otherwise there are elements, then check 
    //from back ,pop all the elemnts that are smaller than x from the list,pop
    //until you encounter a nuber greater than x or the list is empty,and also
    //if the x is smaller than last element in the list then just insert x to
    //list
    if(!head) return head;
    list <LinkedListNode<int>*> l;
    LinkedListNode<int>* ptr=head;
    //this is to populate the list,so that at all points the maximum node will
    //we present at the front of the list
    while(ptr!=NULL){
        while(!l.empty()&&l.back()->data<ptr->data) l.pop_back();
        l.push_back(ptr);
        ptr=ptr->next;
    }
    ptr=head;
    //to populate arbit ,as we iterate we can get the ,maximum element on the
    //roght side of the node at the front od the list, as but we need to check
    //if the lement at first and the ptr are both same, if it is then pop front
    //the the list will point to the maximum element on the right.
    while(ptr!=NULL){
        //to point arbit of last node to null, as there are no node after the 
        //last node
        if(ptr->next==NULL) ptr->arbit=NULL;
        else{
            if(l.front()==ptr) l.pop_front();
            ptr->arbit=l.front();
        }
        ptr=ptr->next;
    }
    return head;
}
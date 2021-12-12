class Solution {
    public boolean isPalindrome(ListNode head) {
        Stack<Integer>s=new Stack<Integer>();
        ListNode ptr=head;
        while(ptr!=null)
        {
            s.push(ptr.val);
            ptr=ptr.next;
        }
        ptr=head;
        while(ptr.next!=null){
            if(s.pop()!=ptr.val){
                return false;
            }
            ptr=ptr.next;
        }
        return true;
    }
}
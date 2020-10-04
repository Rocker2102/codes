/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head=new ListNode(0);
        ListNode l=head;
        while(l1!=null && l2!=null){
            if(l1.val<=l2.val){
                l.next=l1;
                l1=l1.next;
            }
            else if(l1.val>l2.val){
                l.next=l2;
                l2=l2.next;
            }
            l=l.next;
        }
        if(l1==null){
                l.next=l2;
            }
            if(l2==null){
                l.next=l1;
            }
        return head.next;
    }
}

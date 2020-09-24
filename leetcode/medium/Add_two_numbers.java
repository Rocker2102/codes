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
class Add_two_numbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l=new ListNode(0);
        ListNode ptr=l;
        int c=0;
        while(l1!=null || l2!=null){
            int a,b;
            if(l1==null)
                a=0;
            else
                a=l1.val;
            if(l2==null)
                b=0;
            else
                b=l2.val;
            int sum=c+ a + b;
            c=sum/10;
            ptr.next= new ListNode(sum%10);
            ptr=ptr.next;
            if(l1!=null)
                l1=l1.next;
            if(l2!=null)
                l2=l2.next;
        }
        if(c>0)
            ptr.next=new ListNode(c);
        
        return l.next;
    }
}

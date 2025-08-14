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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = new ListNode();
        ListNode node = head;
        ListNode node2 = head;
        int count = 0;
        while(node!=null){
            node = node.next;
            count++;
        }
        if (count == 1){
            p = null;
            return p;
        }
        int x = count - n;
        int temp = x;
        while(x>1){
            node2 = node2.next;
            x--;
        }
        if(temp==0){
            head = head.next;
        }
        else{
            node2.next = node2.next.next;
        }
        return head;
    }
}
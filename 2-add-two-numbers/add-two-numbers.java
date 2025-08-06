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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // ListNode node1 = l1;
        // ListNode node2 = l2;
        // ListNode node3 = new ListNode();
        // ListNode node4 = new ListNode();
        // int c = 0;
        
        // while(node1 != null && node2 != null && node1.next !=null && node2.next !=null){
        //     int sum = 0; 
        //     sum = c + node1.val + node2.val;
        //     c = sum / 10;
        //     sum = sum % 10;
        //     node1.val = sum;
        //     node1 = node1.next;
        //     node2 = node2.next;
        //     if(node1.next == null || node2.next == null){
        //     int x = node1.val + c + node2.val;
        //     node2 = node2.next;
        //     node1.val = x%10;
        //     if(node2!=null){
        //         node1.next = node2;
        //     }
            
        //     c = x/10;
        // }
        // }
        // while(node1 != null && node1.next !=null){
        //     int sum = 0; 
        //     sum = c + node1.val;
        //     c = sum / 10;
        //     sum = sum % 10;
        //     node1.val = sum;
        //     node1 = node1.next;
        //     if(node1.next == null){
        //     int x = node1.val + c;
        //     node1.val = x%10;
        //     c = x/10;
        // }
        // }
        
        // while(node2 != null && node1.next != null){
        //     int sum = 0; 
        //     sum = c + node2.val;
        //     c = sum / 10;
        //     sum = sum % 10;
        //     node1 = node1.next;
        //     node2.val = sum;
            
        //     node2 = node2.next;
        // //     if(node1.next == null){
        // //     int x = node1.val + c;
        // //     node1.val = x%10;
        // //     c = x/10;
        // // }
        // }
        // // node1.next = c;
        // // if(node1.next!=null){
        // // int x = node1.val + c;
        // // node1 = node4;
        // // node4.val = x%10;
        // // c = x/10;}
        // node3.val = c;
        // if(c>0){
        //     node1.next = node3;
        // }
        // return l1;
        ListNode dummy = new ListNode();
        ListNode res = dummy;
        int total = 0, carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            total = carry;

            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            int num = total % 10;
            carry = total / 10;
            dummy.next = new ListNode(num);
            dummy = dummy.next;
        }

        return res.next;   
    }
}
// 24. Swap Nodes in Pairs
// My solution
// Just good
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // a -> 1 -> 2 -> 3
        // a-> 2 -> 1-> 3 -> 4
        // now next head
        // a -> 2 -> 1 ->
        ListNode* hair = new ListNode(0, head);
        ListNode* now = hair;
        while(head != nullptr && head->next != nullptr){
            ListNode* next = head->next;
            now->next = next;
            head->next = next->next;
            next->next = head;
            now = head;
            head = now->next;
        };
        return hair->next;
    }
};
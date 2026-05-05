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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even && even->next) {
            odd->next = even->next;   // link next odd node
            odd = odd->next;          // move odd pointer

            even->next = odd->next;   // link next even node
            even = even->next;        // move even pointer
        }

        // attach even list at end of odd list
        odd->next = evenHead;

        return head;
    }
};
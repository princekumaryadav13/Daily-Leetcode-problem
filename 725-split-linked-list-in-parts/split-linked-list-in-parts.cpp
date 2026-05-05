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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* te = head;
        while (te) {
            count++;
            te = te->next;
        }
        int a = count / k;
        int b = count % k;

        vector<ListNode*> ans;
        ListNode* temp = head;
        ListNode* t = head;
        while (k) {
            ListNode* t = temp;
            int size = a + (b > 0 ? 1 : 0);

            if (b > 0)
                b--;

            // move size-1 steps
            for (int i = 1; i < size; i++) {
                if (temp)
                    temp = temp->next;
            }
            if (temp) {
                ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }

            ans.push_back(t);

            k--;
        }
        return ans;
    }
};
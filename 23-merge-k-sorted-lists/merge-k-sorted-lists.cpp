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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>st;
        for(auto x : lists){
            while(x){
                st.push_back(x->val);
                x = x->next;
            }
        }
        sort(st.begin(),st.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(int i=0;i<st.size();i++){
           temp->next = new ListNode(st[i]);  // ✅ create node
            temp = temp->next;
        }
        return dummy->next;
    }
};
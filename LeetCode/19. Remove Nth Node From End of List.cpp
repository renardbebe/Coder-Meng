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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;
        
        ListNode* ans = new ListNode(0, head);
        ListNode* p1 = ans;
        ListNode* p2 = p1->next;
        
        for (int i = n; i > 0; i--) {
            p2 = p2->next;
        }
        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // remove the node after p1
        p1->next = p1->next->next;
        
        return ans->next;
    }
};
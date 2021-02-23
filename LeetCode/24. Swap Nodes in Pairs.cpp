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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1 = head;
        if (!p1) return NULL;
        ListNode* p2 = head->next;
        if (!p2) return head;
        
        while (p2) {
            // just swap value
            swap(p1->val, p2->val);
            
            p1 = p1->next ? p1->next->next : NULL;
            p2 = p2->next ? p2->next->next : NULL;
        }
        return head;
    }
};
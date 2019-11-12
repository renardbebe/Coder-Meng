/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            // 后移
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};
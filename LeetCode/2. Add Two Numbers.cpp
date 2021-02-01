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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ret(0), *p = &ret;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry) {
            int h = (l1 ? l1->val : 0) + (l2? l2->val : 0) + carry;
            carry = h / 10;
            p->next = new ListNode(h % 10);
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return ret.next;
    }
};
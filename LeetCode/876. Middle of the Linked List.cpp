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
    ListNode* middleNode(ListNode* head) {
        // 使用双指针，fast始终指向以slow为中位数的序列的队尾
        // 快的每次走2步，慢的每次走1步
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
            }
            else {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
};
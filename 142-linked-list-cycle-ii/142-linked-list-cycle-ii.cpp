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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow=head;
        ListNode *fast=head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast -> next -> next;
            if(slow == fast)
                break;
        }
        if(fast == NULL || fast->next == NULL)
        {
            return NULL;
        }
        ListNode* slow2 = head;
        while(slow && slow2)
        {
            if(slow2 == slow) return slow;
            slow2 = slow2->next;
            slow = slow->next;
        }
        return NULL;
    }
};
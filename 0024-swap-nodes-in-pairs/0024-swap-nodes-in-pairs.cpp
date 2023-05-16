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
        if(!head || !head->next)return head;
        ListNode *start=head;
        ListNode *first = head;
        ListNode *sec = head->next;
        ListNode *ns=sec->next;
        first->next = ns;
        sec->next = first;
        first->next = swapPairs(ns);
        return sec;

    }
};
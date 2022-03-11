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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return NULL;
        if(left == right) return head;
        int count = 1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr && count <= left-1)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode *start;
        start = prev;
        ListNode *end = curr;
        ListNode *next;
        count = 1;
        while(curr && count <= right-left +1)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(start)
         start -> next = prev;
        end->next = curr;
        if(left == 1) return prev;
        return head;
    }
};
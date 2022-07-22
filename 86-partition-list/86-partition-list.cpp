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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode;
        ListNode *r = new ListNode;
        ListNode *ltail = l;
        ListNode *rtail = r;
        while(head)
        {
            if(head->val < x)
            {
                ltail->next = head;
                ltail = ltail->next;
            }
            else
            {
                rtail->next = head;
                rtail = rtail -> next;
            }
            head = head -> next;
        }
        rtail -> next = NULL;
        ltail -> next = r->next;
        return l->next;
    }
};
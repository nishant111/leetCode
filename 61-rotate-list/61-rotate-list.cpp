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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        int count = 0;
        ListNode * curr = head;
        while(curr!=NULL)
        {
            count++;
            curr = curr->next;
        }
        int rotate = k % count;
        if(rotate == 0) return head;
        int i = 1;
        curr = head;
        ListNode *first;
        while(i< count - rotate)
        {
            curr = curr-> next;
            i++;
        }
        first = curr->next;
        curr->next = NULL;
        curr = first;
        while(curr->next!=NULL)
        {
            curr = curr->next;
        }
        curr -> next = head;
        return first;
        
    }
};
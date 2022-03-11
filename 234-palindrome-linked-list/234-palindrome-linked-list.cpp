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
    ListNode* reverse (ListNode *head)
    {
        if(head == NULL) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *tmp;
        while(fast && fast->next)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode *l2 ;
        if(fast == NULL)
        {
            tmp->next = NULL;
            l2 = reverse(slow);
        }
        else if(fast->next ==NULL)
        {
            tmp->next = NULL;
            l2 = reverse(slow->next);
        }
        
        while(l2 && l1)
        {
            if(l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==NULL && l2==NULL) return true;
        return false;
    }
};
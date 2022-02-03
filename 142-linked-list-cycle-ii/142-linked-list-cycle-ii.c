/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next ==NULL) return NULL;
    node *slow=head;
    node *fast=head;
    
    slow = head->next;
    fast = fast ->next -> next;
    while(slow!=NULL && fast !=NULL && fast->next!=NULL)
    {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow ==NULL || fast == NULL) return NULL; //no cycle
    node *s1=head;
    while(s1!=slow && slow !=NULL && s1 !=NULL)
    {
        s1 = s1->next;
        slow = slow->next;
    }
    if(slow ==NULL && s1 ==NULL)return NULL;
    return slow;
}
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
    ListNode* rev(ListNode* curr){
        ListNode *prev = NULL;
        ListNode *nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = rev(slow->next);
        ListNode *l2 = slow->next;
        ListNode *l1 = head;
        while(l2){
            if(l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};
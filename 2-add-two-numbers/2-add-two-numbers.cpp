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
        ListNode *dummy = new ListNode;
        ListNode *curr = dummy;
        
        int carry = 0;
        while(l1!=NULL || l2!=NULL)
        {
            int sum = 0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carry;
            curr -> next = new ListNode(sum % 10);
            carry = sum / 10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            curr = curr-> next;
        }
        if(carry>0)
        {
            curr -> next = new ListNode(carry);
        }
        return dummy->next;
    }
};
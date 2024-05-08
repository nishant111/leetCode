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
    ListNode* reverse(ListNode* curr){
        ListNode *prev= NULL;
        ListNode* n;
        while(curr){
            n = curr->next;
            curr->next=prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* rev = reverse(head);
        ListNode* curr = rev;
        curr=rev;
        ListNode* ans = new ListNode();
        ListNode * h = ans;
        int carry = 0;
        while(curr){
            //cout<<"carry is "<<carry<<"\n";
            int twice = (2*(curr->val)) + carry;
            int digit = twice % 10;
            carry = twice/10;
            h->next = new ListNode(digit);
            h = h->next;
            curr = curr->next;
        }
        if(carry){
            h->next = new ListNode(carry);
        }
        return reverse(ans->next);
    }
};
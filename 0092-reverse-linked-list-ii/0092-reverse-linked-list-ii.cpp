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
        if(head == NULL) return head;
        if(left == right) return head;
        ListNode *curr = head;
        ListNode *l=NULL;
        ListNode *start = NULL;
        ListNode *r=NULL;
        int count = 1;
        while(curr){
            if(left != 1 && count + 1 == left){
                start = curr;
            }
            if(count == left){
                l = curr;
            }
            if(count == right){
                r = curr;
            }
            if(l && r && start)
                break;
            curr = curr->next;
            count++;
        }
        ListNode *end = r->next;
        // we have pointers to left and right end, start reversing now
        ListNode *prev = end;
        ListNode *nxt;
        while(l!=end){
            nxt = l->next;
            l->next = prev;
            prev = l;
            l = nxt;
        }
        if(start!=NULL){
            start->next = prev;
            return head;
        }
        return prev;
    }
};
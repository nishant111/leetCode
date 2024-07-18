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
    ListNode *middle=NULL;
    ListNode * findMiddle(ListNode *start){
        ListNode *fast = start;
        ListNode *slow = start;
        while(fast && fast->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
        }
        middle = slow->next;
        slow->next = NULL;
        return middle;
    }
    
    ListNode *reverse(ListNode *curr){
        ListNode *prev = NULL;
        ListNode *nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nxt;
        }
        return prev;
    }
    
    
    void reorderList(ListNode* head) {
        ListNode* l1 = head;
        ListNode *start = head;
        ListNode *mid = findMiddle(start);
        ListNode * l2 =NULL;
        if(mid)
            l2 = reverse(mid);
        
        ListNode *curr = new ListNode();
        while(l1 || l2 != NULL){
            curr->next = l1;
            l1=l1->next;
            curr=curr->next;
            if (l2) {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        return;
    }
};
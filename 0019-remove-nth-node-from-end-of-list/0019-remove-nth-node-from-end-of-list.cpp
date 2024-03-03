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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *behind = head;
        ListNode *ahead = head;
        while(ahead != NULL && n>0){
            ahead= ahead->next;
            n--;
        }
        if(n==0 && ahead){
            while(ahead->next != NULL){
                behind = behind -> next;
                ahead = ahead -> next;
            }
            ListNode *toDelete = behind->next;
            behind->next = behind->next->next;
            toDelete->next=NULL;
            delete(toDelete);
            return head;
        }
        else {
            // head node is toDelete node.
            return head->next;
        }
    }
};
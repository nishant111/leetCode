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
    ListNode * h;
    int count=0;
    Solution(ListNode* head) {
        h = head;
        ListNode* curr = h;
        while(curr!=NULL) {
            count++;
            curr=curr->next;
        }
    }
    
    int getRandom() {
        int tmp = rand() % (count);
        ListNode *curr = h;
        int counted =0 ;
        while(curr) {
            if(counted == tmp)
                return curr->val;
            counted++;
            curr=curr->next;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
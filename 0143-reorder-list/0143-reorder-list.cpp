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
    void reorderList(ListNode* head) {
        vector<ListNode *> l;
        ListNode *curr = head;
        while(curr){
            l.push_back(curr);
            curr=curr->next;
        }
        
        int end = l.size()-1;
        int start = 0;
        curr = head;
        while(start<end){
            l[start]->next = l[end];
            start++;
            if(start!=end)
                l[end]->next = l[start];
            end--;
            l[start]->next = NULL;
        }
        return;
    }
};
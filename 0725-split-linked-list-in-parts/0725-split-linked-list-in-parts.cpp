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
    int count(ListNode *curr){
        if(!curr) return 0;
        int ret = 0;
        while(curr){
            curr=curr->next;
            ret++;
        }
        return ret;
    }
    vector<ListNode*> breakList(ListNode *curr, int groupSize, int extra){
        if(!curr) return {NULL};
        int currCount = 1;
        ListNode * head = curr;
        vector<ListNode*> ans;
        while(curr){
            while(currCount != groupSize){
                curr = curr->next;
                currCount++;
            }
            ans.push_back(head);
            if (!extra){
                head = curr->next;
                curr->next = NULL;
                // start the next group
                curr=head;
                // reset the current count to restart counting
                currCount = 1;
            }
            if(extra){
                // add one extra node
                head = curr->next->next;
                curr->next->next = NULL;
                curr=head;
                currCount = 1;
                extra--;
            }
            
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = count(head);
        vector<ListNode*> ans;
        if(k>=n){
            //only option is to break in group of 1's
            ans = breakList(head, 1, 0);
            while(ans.size()<k){
                ans.push_back(NULL);
            }
            return ans;
        }
        else if(n>k && n%k == 0){
            ans = breakList(head, n/k, 0);
            return ans;
        }
        else if(n>k && n%k != 0){
            // break in base size and keep accomodating
            // extra nodes in each break
            ans = breakList(head, n/k, n%k);
        }
        return ans;
    }
};
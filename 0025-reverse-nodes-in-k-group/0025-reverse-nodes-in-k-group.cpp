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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check whether k nodes are available
        ListNode* temp = head;
        int count = 0;

        while(temp && count < k) {
            temp = temp->next;
            count++;
        }

        if(count < k)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;

        int count2 = 0;        // reverse first k nodes
        while(curr && count2 < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count2++;
        }

        // curr will be pointing to k+1 th node
        // recursion for rest of the nodes n-k
        if(curr){
            ListNode* newhead = reverseKGroup(curr, k);
            head->next = newhead;
        }

        return prev;
    }
};
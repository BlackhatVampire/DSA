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

        int count1 = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            count1 ++;
        }
        if(count1 <k) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;

        int count = 0;
        while(curr && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(curr){
            ListNode* newhead=  reverseKGroup(curr, k);
            head->next = newhead;
        }
        return prev;
    }
};
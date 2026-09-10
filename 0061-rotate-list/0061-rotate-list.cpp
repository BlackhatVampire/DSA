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
    ListNode* rotateRight(ListNode* head, int k) {
        // make the list into cycle ..means point your last node to the head node
        int n = 1;
        ListNode* temp = head;
        if(head == NULL || head->next == NULL) return head;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        k = k%n;
        if(k==0) return head;             // it repeat itself
        temp->next =head;
        temp = head;                         // reusing temp pointer
        for(int i = 1 ;i<n-k ;i++){
            temp =temp->next;
        }
        ListNode* newnode = temp->next;         //n-k+1
        temp->next = NULL;
        head = newnode;
        return head;
    }
};
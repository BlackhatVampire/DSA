/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* moveksteps(ListNode* head, int k) {
        ListNode* temp = head;
        while (k--) {
            temp = temp->next;
        }
        return temp;
    }
    int checklength(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }
        return n;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int l1 = checklength(headA);
        int l2 = checklength(headB);
        int k = 0;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if (l1 > l2) {
            k = l1 - l2;
            ptr1 = moveksteps(ptr1, k);
        } else {
            k = l2 - l1;
            ptr2 = moveksteps(ptr2, k);
        }
        while (ptr1 && ptr2) {
            if (ptr1 == ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
        /*ptr1->val == ptr2->val

        Because values can be identical in completely different nodes:
        List A: 1 → 7 → 9
        List B: 4 → 7 → 9

        */
    }
};
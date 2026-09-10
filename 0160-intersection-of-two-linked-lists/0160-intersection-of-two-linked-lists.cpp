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
    ListNode* moveksteps(ListNode *head , int k){
        ListNode* temp = head;
        while(k--){
            temp = temp->next;
        }
        return temp;
    }
    int checklength(ListNode *head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        return n;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        int l1 = checklength(list1);
        int l2 = checklength(list2);
        int k = 0;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        if(l1>l2){
            k = l1-l2;  
            ptr1 = moveksteps(list1,k);
        }
        else{
            k=l2-l1;
            ptr2 = moveksteps(list2,k);
        }
        while(ptr1 && ptr2){
            if(ptr1==ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* previous = dummy;

        for(int i = 0; i < left - 1; i++) {
            previous = previous->next;
        }

        ListNode* current = previous->next;

        for(int i = 0; i < right - left; i++) {
            ListNode* temp = current->next;
            current->next = temp->next;
            temp->next = previous->next;
            previous->next = temp;
        }

        return dummy->next;        
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* previous = dummy;
        ListNode* current = head;

        while(current != NULL) {
            if(current->next != NULL && current->val == current->next->val) {
                while(current->next != NULL && current->val == current->next->val) {
                    current = current->next;
                }
                previous->next = current->next;
            } 
            else {
                previous = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};
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
        if(head == NULL || head->next == NULL || k == 0) 
            return head;

        ListNode* tail = head;
        int length = 1;

        while(tail->next != NULL) {
            length++;
            tail = tail->next;
        }

        k %= length; 
        tail->next = head;
        int end = length - k; 
        while(end-- > 0) 
            tail = tail->next;

        head = tail->next;
        tail->next = NULL;

        return head;
    }
};
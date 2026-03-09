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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *current = head;

        while(current && current->next) {
            ListNode *nextPair = current->next->next;
            ListNode *second = current->next;

            second->next = current;
            current->next = nextPair;
            prev->next = second;
            prev = current;
            current = nextPair;
        }

        return dummy.next;        
    }
};
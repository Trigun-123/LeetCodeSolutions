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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* write = head->next;
        ListNode* read = write;

        while(read != NULL) {
            int sum = 0;
            while(read->val != 0) {
                sum += read->val;
                read = read->next;
            }
            write->val = sum;
            read = read->next;
            write->next = read;
            write = write->next;
        }

        return head->next;
    }
};
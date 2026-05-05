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
        if(head == NULL) {
            return head;
        }

        ListNode *fast = head, *slow = head;
        int n = 0;

        for(int i = 0; i < k; i++) {
            fast = fast->next;
            n++;

            if(fast == NULL) { 
                k -= n;
                k %= n;
                i = -1;
                fast = head;
            }
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};
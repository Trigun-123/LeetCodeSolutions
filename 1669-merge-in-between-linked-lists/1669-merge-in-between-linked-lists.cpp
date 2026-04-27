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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pointer = list1;

        for(int i = 0; i < a - 1; i++) {
            pointer = pointer->next;
        }    
        
        ListNode* qtr = pointer->next;

        for(int i = 0; i < b-a+1; i++) {
            qtr = qtr->next;
        }    
        
        pointer->next = list2;

        while(list2->next) {
            list2 = list2->next;
        }
            
        list2->next = qtr;
        
        return list1;
    }
};
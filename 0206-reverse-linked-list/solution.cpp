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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* agla = NULL;
        
        while(head != NULL){
            agla = head->next;
            head->next = prev;
            prev = head;
            head = agla;
        }
        return prev;
    }
};

// ListNode* reverseList(ListNode* head) {
//     ListNode* prev = nullptr;
//     ListNode* next = nullptr;

//     while (head != nullptr) {
//         next = head->next; // Store next node
//         head->next = prev; // Reverse current node's pointer
//         prev = head;       // Move pointers one position ahead
//         head = next;
//     }
//     return prev;
// }


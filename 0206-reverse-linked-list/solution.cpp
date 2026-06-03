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
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newHead = reverseList(head->next);//recursion chalegi

        ListNode* front = head->next;
        front->next=head;//direction ulti hogyi isse
        head->next=nullptr;//and last wala null ki taraf point now
        return newHead;

    }
};

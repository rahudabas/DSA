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
    ListNode* rec(ListNode* tmp){
        if(tmp==NULL || tmp->next==NULL){
            return tmp;
        }
        ListNode* head1=rec(tmp->next);
        ListNode* front=tmp->next;
        front->next=tmp;
        tmp->next=NULL;
        return head1;
    }
    ListNode* reverseList(ListNode* head) {
        return rec(head);
    }
};

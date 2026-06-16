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
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head, *prev=NULL, *forw=head->next;

        while(temp!=NULL){
            temp->next=prev;
            prev=temp;
            temp=forw;
            if(temp!=NULL)forw=forw->next;
        }
        return prev;
    }
};

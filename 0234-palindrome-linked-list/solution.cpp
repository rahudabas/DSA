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

    // ListNode* reverse(ListNode* head){
    //     if(head==NULL || head->next==NULL){
    //         return head;
    //     }
    //     ListNode* newHead=reverse(head->next);
    //     ListNode* front=head->next;
    //     front->next=head;
    //     head->next=NULL;
    //     return newHead;
    // }//recursive m reverse

    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front=head;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;//reverse krdiya link
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL){
            return true;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }//slow is mid element

        ListNode* newHead= reverse(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;

        while(second!=NULL){
            if(second->val!=first->val){
                reverse(newHead);
                return false;
            }
            second=second->next;
            first=first->next;
        }
        reverse(newHead);
        return true;

    }
};

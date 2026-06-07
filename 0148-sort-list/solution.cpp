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

    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge2sorted(ListNode* lefthead, ListNode* righthead){
        ListNode* dNode=new ListNode(-1);
        ListNode* temp=dNode;

        while(lefthead!=NULL && righthead!=NULL){
            if(lefthead->val <righthead->val){
                temp->next=lefthead;
                temp=lefthead;
                lefthead=lefthead->next;
            }
            else{
                temp->next=righthead;
                temp=righthead;
                righthead=righthead->next;
            }
        }
        if(lefthead)temp->next=lefthead;
        if(righthead)temp->next=righthead;

        return dNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* middle= findmiddle(head);

        ListNode* lefthead=head, *righthead=middle->next;
        middle->next=NULL;

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        //dono base tk jayege

        return merge2sorted(lefthead,righthead); 
        // sorted ll hoge left and right base case s utha rhe h 
    }
};

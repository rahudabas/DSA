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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        ListNode* front=dummy;
        while(t1!=NULL || t2!=NULL || carry!=0){
            int ans=0;
            if(t1!=NULL){
                ans+=t1->val;
                t1=t1->next;
            }
            if(t2!=NULL){
                ans+=t2->val;
                t2=t2->next;
            }
            ans+=carry;
            carry=ans/10;
            ans=ans%10;
            ListNode* fre=new ListNode(ans);
            front->next=fre;
            front=front->next;

        }
        return dummy->next;
    }
};

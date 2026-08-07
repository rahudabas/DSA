/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0;
        int n2=0;
        ListNode* t1=headA;
        ListNode* t2=headB;

        while(t1!=NULL){
            n1++;
            t1=t1->next;
        }
        while(t2!=NULL){
            n2++;
            t2=t2->next;
        }
        if(n1>n2){
            t1=headA;
            t2=headB;
            for(int i=0;i<n1-n2;i++){
                t1=t1->next;
            }
            while(t1!=t2){
                if(t1==t2)return t1;
                t1=t1->next;
                t2=t2->next;
            }
            return t1;
        }
        else{
            t1=headA;
            t2=headB;
            for(int i=0;i<n2-n1;i++){
                t2=t2->next;
            }
            while(t1!=t2){
                if(t1==t2)return t1;
                t1=t1->next;
                t2=t2->next;
            }
            return t1;
        }
        return t1;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* ptr = head;
    struct ListNode* ptr2 = head->next;

    while(ptr2 != NULL){
        if(ptr->val == ptr2->val){
            ptr2 = ptr2->next;
            ptr->next = ptr2;
        }
        else{
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
    }
    return head;
}

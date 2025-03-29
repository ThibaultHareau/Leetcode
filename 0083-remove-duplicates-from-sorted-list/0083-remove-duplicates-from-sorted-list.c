/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* pointer = head;
    while(pointer != NULL && pointer->next != NULL){
        if (pointer->val == pointer->next->val){
            pointer->next = pointer->next->next;
        }
        else {
            pointer = pointer->next;
        }
    }
    return head;
}
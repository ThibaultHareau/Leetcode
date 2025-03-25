/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode* output = head->next;
    head->next = head->next->next;
    output->next = head;
    struct ListNode* tmp;
    while (head->next != NULL && head->next->next != NULL){
        tmp = head->next->next;
        head->next->next = tmp->next;
        tmp->next = head->next;
        head->next = tmp;
        head = head->next->next;
    }
    return output;
}
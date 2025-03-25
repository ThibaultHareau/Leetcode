/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int step = 0;
    struct ListNode* head1 = head;
    struct ListNode* head2 = head;
    while (head1 != NULL){
        head1 = head1->next;
        if (step > n) head2 = head2->next;
        step ++;
    }
    if (step <= n) return head->next;
    if (head2->next != NULL) head2->next = head2->next->next;
    else return NULL;
    return head;
}
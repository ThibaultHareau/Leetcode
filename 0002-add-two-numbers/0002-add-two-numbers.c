/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode *) malloc(sizeof(struct ListNode));
    int tmp = l1->val + l2->val;
    result->val = tmp%10;
    result->next = NULL;
    l1 = l1->next;
    l2 = l2->next;
    struct ListNode* current = result;
    while(l1 != NULL || l2 != NULL){
        current->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        current->next->next=NULL;
        if (l1 == NULL){
            tmp = l2->val + tmp/10;
            current->next->val = tmp%10;
            l2 = l2->next;
        }
        else if (l2 == NULL){
            tmp = l1->val + tmp/10;
            current->next->val = tmp%10;
            l1 = l1->next;
        }
        else {
            tmp = l1->val + l2->val + tmp/10;
            current->next->val = tmp%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        current = current->next;
    }
    if (tmp/10 == 1){
        current->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        current->next->val = 1;
        current->next->next=NULL;
    }
    return result;
}
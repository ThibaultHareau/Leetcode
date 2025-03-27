/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k==1) return head;
    struct ListNode nodezero = {0, head};
    struct ListNode *previous;
    previous = &nodezero;
    head = previous;
    struct ListNode *queue[k];
    struct ListNode *endpoint = previous->next;
    int i;
    while(previous->next != NULL){
        endpoint = previous->next;
        i=0;
        while (i<k && endpoint != NULL){
            queue[i] = endpoint;
            endpoint = endpoint->next;
            i++;
        }
        if (i<k) return head->next;
        //printf("%d \n", queue[k-1]->val);
        previous->next = queue[k-1];
        i = k-2;
        while(i>=0){
            queue[i+1]->next = queue[i];
            i--;
        }
        queue[0]->next = endpoint;
        previous = queue[0];
    }
    return head->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode *head;
    struct ListNode *current;
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    }
    else {
        head = list2;
        list2 = list2->next;
    }
    current = head;
    while (list1 != NULL && list2 != NULL){
        if (list1->val <= list2->val){
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1==NULL) current->next = list2;
    else current->next = list1;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    //Use merge for two lists then merge
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];
    lists[0] = mergeTwoLists(lists[0], lists[1]);
    if (listsSize == 2) return lists[0];
    for (int i=2;i<listsSize;i++){
        lists[0] = mergeTwoLists(lists[0], lists[i]);
    }
    return lists[0];
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    typedef struct node
    {
        int value;
        int position;
        struct node* next;
    }
    node;
    node* head = NULL;
    head = (node *) malloc(sizeof(node));
    head->value = nums[0];
    head->position = 0;
    head->next = NULL;
    node* current;
    for (int i=1;i<numsSize;i++){
        current = head;
        while(current != NULL){
            if (nums[i] + current->value == target){
                result[0] = i;
                result[1] = current->position;
                return result;
            }
            if (nums[i] == current->value){
                break;
            }
            if (current->next == NULL){
                current->next = (node *) malloc(sizeof(node));
                current->next->value = nums[i];
                current->next->position = i;
                current->next->next = NULL;
                break;
            }
            current = current->next;
        }
    }
    return result;
}
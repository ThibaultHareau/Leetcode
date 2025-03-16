/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int *positions = (int *)calloc(sizeof(int), 2000000001);
    for (int i=0; i<numsSize; i++){
        if (target-nums[i]+1000000000 < 2000000001 && target-nums[i]+1000000000>0){
            if (positions[target-nums[i]+1000000000] != 0){
                result[0] = positions[target-nums[i]+1000000000]-1;
                result[1] = i;
                free(positions);
                return result;
            }
        }
        if (positions[nums[i]+1000000000] == 0){
            positions[nums[i]+1000000000] = i+1;
        }
    }
    free(positions);
    return result;
}
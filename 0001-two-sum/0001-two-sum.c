/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize return array
    int* result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    // Prepare the hash table based on target range [-10^9; 10^9] <=> [-SIZE;SIZE]
    int SIZE = 1000000000;
    int *positions = (int *)calloc(sizeof(int), 2*SIZE+1);
    // Iterate through the nums array
    for (int i=0; i<numsSize; i++){
        // Test if the target is reachable from nums[i] based on target range.
        if (target-nums[i]+SIZE < 2*SIZE+1 && target-nums[i]+SIZE>0){
            // If the corresponding number has already been encountered, return the output
            if (positions[target-nums[i]+SIZE] != 0){
                result[0] = positions[target-nums[i]+SIZE]-1;
                result[1] = i;
                free(positions);
                return result;
            }
        }
        // If this is the first time encountering nums[i], add the position in the hash table
        if (positions[nums[i]+SIZE] == 0){
            positions[nums[i]+SIZE] = i+1;
        }
    }
    free(positions);
    return result;
}
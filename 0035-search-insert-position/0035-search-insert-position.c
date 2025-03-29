int searchInsert(int* nums, int numsSize, int target) {
    if (nums[0] > target) return 0;
    if (nums[numsSize-1] < target) return numsSize;
    int left = 0;
    int right = numsSize-1;
    int split;
    while(left<right){
        split = (left+right)/2;
        if (nums[split] == target) return split;
        if (nums[split] < target) {
            if (split == left) left++;
            else left = split;
        }
        else right = split;
    }
    return right;
}
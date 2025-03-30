void nextPermutation(int* nums, int numsSize) {
    int pivotindex = -1;
    for (int i=numsSize-2; i>=0; i--){
        if (nums[i] < nums[i+1]) {
            pivotindex = i;
            break;
        }
    }
    int temp;
    int i;
    int left = 0;
    if (pivotindex != -1){
        i = pivotindex+1;
        int swap;
        for (int i=numsSize-1;i>pivotindex;i--){
            if (nums[i] > nums[pivotindex]) {
                swap = i;
                break;
            }
        }
        temp = nums[pivotindex];
        nums[pivotindex] = nums[swap];
        nums[swap] = temp;
        left = pivotindex+1;
    }
    int right = numsSize-1;
    while(left < right){
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }  
}
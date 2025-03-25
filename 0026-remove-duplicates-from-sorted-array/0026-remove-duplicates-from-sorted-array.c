int removeDuplicates(int* nums, int numsSize) {
    int i=1;
    int k=0;
    int previous=nums[0];
    while (i<numsSize){
        if (previous != nums[i]){
            k++;
            nums[k] = nums[i];
            previous = nums[i];
        }
        i++;
    }
    return k+1;    
}
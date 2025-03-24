int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), comp);
    int result;
    if (target>=0){
        result = INT_MAX;
    }
    else {
        result = INT_MIN;
    }
    int currentres;
    int j;
    int k;
    for (int i=0;i<numsSize-2;i++){
        if (3*nums[i] > target + abs(target-result)) return result;
        j = i+1;
        k = numsSize-1;
        while (j!=k){
            currentres = nums[i]+nums[j]+nums[k];
            if (abs(target-result) > abs(target-currentres)){
                result = currentres;
                if (target == result) return result;
            }
            if (currentres <= target) j+=1;
            else k-=1;
        }
    }
    return result;
}
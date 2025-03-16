void updatearray(int *previouscurrent,int totalindex, int current){
    if (totalindex >= 1){
        previouscurrent[1] = previouscurrent[0];
    }
    previouscurrent[0] = current;
    return;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *previouscurrent = (int *)malloc(sizeof(int) * 2);
    int stopindex = 1 + ((nums1Size + nums2Size)/2);
    int i = 0;
    int j = 0;
    while (i+j < stopindex){
        if (i >= nums1Size) {
            // Only nums2 available
            updatearray(previouscurrent, i+j, nums2[j]);
            j++;
            continue;
        }
        if (j >= nums2Size) {
            // Only nums1 available
            updatearray(previouscurrent, i+j, nums1[i]);
            i++;
            continue;
        }
        if (nums1[i] <= nums2[j]){
            // Pick element from nums1
            updatearray(previouscurrent, i+j, nums1[i]);
            i++;
            continue;
        }
        // Pick element from num2
        updatearray(previouscurrent, i+j, nums2[j]);
        j++;
        continue;
    }
    double result;
    if ((nums1Size + nums2Size)%2 == 0){
        result =  (previouscurrent[0] + previouscurrent[1]) / 2.;
        free(previouscurrent);
        return result;
    }
    result =  previouscurrent[0];
    free(previouscurrent);
    return result;
}
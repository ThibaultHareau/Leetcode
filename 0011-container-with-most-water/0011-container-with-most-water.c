int maxArea(int* height, int heightSize) {
    int result = 0;
    int left = 0;
    int right = heightSize - 1;
    int volume;
    while (left != right){
        if (height[left] <= height[right]) volume = height[left] * (right - left);
        else volume = height[right] * (right - left);
        if (volume > result) result = volume;
        if (height[right] < height[left]) right --;
        else left ++;
    }
    return result;
}
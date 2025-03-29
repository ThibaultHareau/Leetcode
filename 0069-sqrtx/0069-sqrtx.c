int mySqrt(int x) {
    if (x<=1) return x;
    int i = 1;
    while(x/i > i){
        i++;
    }
    return x/i;
}